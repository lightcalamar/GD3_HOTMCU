void CargaJPG(int ImagenID)
{
    GD.cmd_loadimage(0, 0);
    GD.load(getdir(directory, ImagenID)); 
}  
