#include <gl.h> // Header File For The OpenGL32 Library

class Skybox
{
public:
	float width;
	float height;
	float length;

	Skybox(float w = 50.0f, float h = 50.0f, float l = 200.0f) {
		width = w;
		height = h;
		length = l;
	}

	void draw(int texture) const
	{
		// X Coordinates: [-width, width]
		// Y Coordinates: [0, length]
		// Z Coordinates: [0, height]
		glColor3f(1.0, 1.0, 1.0);
		glPushMatrix();

		// Bottom
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(-width, 0, 0);

		glTexCoord2d(1, 0);
		glVertex3f(width, 0, 0);

		glTexCoord2d(1, 1);
		glVertex3f(width, 0, -length);

		glTexCoord2d(0, 1);
		glVertex3f(-width, 0, -length);

		// Back
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexCoord2d(0, 0);
		glVertex3f(-width, 0, -length);

		glTexCoord2d(1, 0);
		glVertex3f(width, 0, -length);

		glTexCoord2d(1, 1);
		glVertex3f(width, height, -length);

		glTexCoord2d(0, 1);
		glVertex3f(-width, height, -length);

		// Right
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexCoord2d(0, 0);
		glVertex3f(width, 0, 0);

		glTexCoord2d(1, 0);
		glVertex3f(width, 0, -length);

		glTexCoord2d(1, 1);
		glVertex3f(width, height, -length);

		glTexCoord2d(0, 1);
		glVertex3f(width, height, 0);

		// Front
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexCoord2d(0, 0);
		glVertex3f(width, 0, 0);

		glTexCoord2d(1, 0);
		glVertex3f(width, height, 0);

		glTexCoord2d(1, 1);
		glVertex3f(-width, height, 0);

		glTexCoord2d(0, 1);
		glVertex3f(-width, 0, 0);

		// Left
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexCoord2d(0, 0);
		glVertex3f(-width, 0, 0);

		glTexCoord2d(1, 0);
		glVertex3f(-width, 0, -length);

		glTexCoord2d(1, 1);
		glVertex3f(-width, height, -length);

		glTexCoord2d(0, 1);
		glVertex3f(-width, height, 0);
		glEnd();

		glPopMatrix();
	}
};