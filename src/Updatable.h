
#ifndef INKBALL_UPDATABLE_H
#define INKBALL_UPDATABLE_H

class Updatable{
public:
	virtual void update(double timestep) = 0;
};

#endif //INKBALL_UPDATABLE_H
