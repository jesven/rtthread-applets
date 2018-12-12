#!/bin/env python
import sys
import argparse
import struct

import zlib # for crc32

# debug
from pprint import pprint

# elf_pk elf_name apk_name

elf_name = sys.argv[1]
apk_name = sys.argv[2]

print elf_name + ' ==> ' + apk_name

from elftools.common.py3compat import bytes2str
from elftools.elf.elffile import ELFFile

# text_len
# text_data
# data_len
# data_data
# bss_len

with open(elf_name, 'rb') as f:
    elffile = ELFFile(f)

    for section in elffile.iter_sections():
        # 获取程序段
        if bytes2str(section.name) == 'text':
            #pprint (vars(section))
            section.stream.seek(section.header.sh_offset)
            text_data = section.stream.read(section.header.sh_size)
            text_len = section.header.sh_size

        if bytes2str(section.name) == 'data':
            section.stream.seek(section.header.sh_offset)
            data_data = section.stream.read(section.header.sh_size)
            data_len = section.header.sh_size

        if bytes2str(section.name) == 'bss':
            bss_len = section.header.sh_size
    # end for section in elffile.iter_sections():

print 'text %d byte, data %d byte, bss %d byte.' %(text_len, data_len, bss_len)

#struct app_data_chunk
#{
#	uint32_t total_len;
#	char name[4];
#	uint32_t data_len;
#	uint32_t data_len_space;
#}

pad_len = text_len%4
if pad_len != 0:
    pad_len = 4 - pad_len
    text_data += '#'*pad_len

chunk_text = struct.pack('<I4sII',
        text_len + pad_len + 16,
        'text',
        text_len,
        text_len,
)
chunk_text += text_data

pad_len = data_len%4
if pad_len != 0:
    pad_len = 4 - pad_len
    data_data += '#'*pad_len

chunk_data = struct.pack('<I4sII',
        data_len + pad_len + 16,
        'data',
        data_len,
        data_len + bss_len,
)
chunk_data += data_data

chunk_all = chunk_text + chunk_data
chunk_crc32 = zlib.crc32(chunk_all, 0) & 0xFFFFFFFF

apk_header = struct.pack('<BBhI',
        0x5A,
        0x00,
        -1,
        chunk_crc32,
)

print 'apk size: %d byte, app text: %d byte, app data: %d byte.' \
%(len(apk_header)+len(chunk_all), text_len, data_len + bss_len)

pkg_apk = open(apk_name, 'wb')
pkg_apk.write(apk_header)
pkg_apk.write(chunk_all)


