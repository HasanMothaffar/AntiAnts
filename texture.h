#include <map>
#include <string>

/**********************************************************
 *
 * VARIABLES DECLARATION
 *
 *********************************************************/

// Counter to keep track of the last loaded texture
extern int num_texture;

extern std::map<std::string, int> textures;

/**********************************************************
 *
 * FUNCTION LoadBitmap(char *)
 *
 * This function loads a bitmap file and return the OpenGL reference ID to use that texture
 *
 *********************************************************/

extern int LoadTexture(const char *filename,int alpha=255);
void loadGameTextures();