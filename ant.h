#ifndef ANT_H
#define ANT_H

class Ant
{
public:
	float width;
	float length;
	float height;

	float x;
	float y;
	float z;

	Ant(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;

		this->width = 1;
		this->length = 2;
		this->height = 2;
	}

	void draw() const
	{
		glColor3f(1, 0, 0);
		glPushMatrix();
		glTranslatef(x, y, z);
		glBegin(GL_QUADS);
		// Bottom
		glVertex3f(-width, 0, 0);
		glVertex3f(-width, 0, -length);
		glVertex3f(width, 0, -length);
		glVertex3f(width, 0, 0);

		// Front
		glVertex3f(width, 0, 0);
		glVertex3f(width, height, 0);
		glVertex3f(-width, height, 0);
		glVertex3f(-width, 0, 0);

		// Back
		glVertex3f(-width, 0, -length);
		glVertex3f(width, 0, -length);
		glVertex3f(width, height, -length);
		glVertex3f(-width, height, -length);

		// Left
		glVertex3f(-width, 0, 0);
		glVertex3f(-width, 0, -length);
		glVertex3f(-width, height, -length);
		glVertex3f(-width, height, 0);

		// Right
		glVertex3f(width, 0, 0);
		glVertex3f(width, 0, -length);
		glVertex3f(width, height, -length);
		glVertex3f(width, height, 0);
		glEnd();
		glPopMatrix();
	}
};

#endif // !ANT_H
