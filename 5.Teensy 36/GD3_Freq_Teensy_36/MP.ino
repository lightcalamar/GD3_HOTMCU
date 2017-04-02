void MP()
{
  while(1)
  {
    GD.ClearColorRGB(0x000020);
    GD.Clear();
    MHzMCUGD3();
    GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world");
    GD.swap();
  }
}
