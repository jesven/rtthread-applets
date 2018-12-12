
extern int __text_start__;
extern int __got_start__;
extern int __got_end__;

void reloc_got(int *gbase, int tbase)
{
    int offset;
    int i;
    int s;
    int gs, ge, ts;

    gs = (int)&__got_start__;
    ge = (int)&__got_end__;
    ts = (int)&__text_start__;

    for (i = 0, s = gs; s < ge; s += 4, i++)
    {
        if (gbase[i] >= gs)
        {
            offset = gbase[i] - gs;
            gbase[i] = offset + (int)gbase;
        }
        else
        {
            offset = gbase[i] - ts;
            gbase[i] = offset + tbase;
        }
    }
}
