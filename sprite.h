#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

class CPath
{
private:
  std::string filePath;
public:
  void setPath(std::string path) { filePath = path; }
  std::string getPath() { return filePath; }
};

class CSprite_Image
{
private:
  CPath texPath;
  int width, height;
public:
  CSprite_Image();
  CSprite_Image(std::string path, int w, int h) {
    texPath.setPath(path);
    width =  w;
    height = h;
  }
  ~CSprite_Image();
};

class CSprite_Vertex_Generated {
private:

  unsigned int width;
  unsigned int height;
  unsigned int RGB[3];          //Vertex gen only.
public:
  CSprite_Vertex_Generated();

  unsigned int getWidth()  { return width;  }
  unsigned int getHeight() { return height; }
  unsigned int getRed()     { return RGB[0]; } //Vertex gen only.
  unsigned int getGreen()  { return RGB[1]; } //Vertex gen only.
  unsigned int getBlue()    { return RGB[2]; } //Vertex gen only.

  void setWidth(int w)  { width  = w; }
  void setHeight(int h)  { height = h; }
  void setColor(unsigned int red, unsigned int green, unsigned int blue)
  {
    RGB[0] = red;
    RGB[1] = green;
    RGB[2] = blue;
  }
};


#endif // SPRITE_H_INCLUDED
