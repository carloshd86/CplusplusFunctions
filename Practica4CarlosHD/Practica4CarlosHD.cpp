// Practica4CarlosHD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "consola.h"

struct TEntity;
typedef void(*funcEntity)(TEntity *);


// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	int m_ix;
	int m_iy;
	funcEntity *m_funcs;
	TEntity(funcEntity *funcs, int x, int y)
	{
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;
	}
};



/********/
void setMovement1(TEntity * entity);
void paint1(TEntity * entity);

void setMovement2(TEntity * entity);
void paint2(TEntity * entity);

void setMovement3(TEntity * entity);
void paint3(TEntity * entity);

void setMovement4(TEntity * entity);
void paint4(TEntity * entity);

void setMovement5(TEntity * entity);
void paint5(TEntity * entity);

void checkScreenLimits(TEntity * entity);
void spotEntity(TEntity * entity);
/********/


void checkScreenLimits(TEntity * entity)
{
	int screenOffsetX ;
	int screenOffsetY;
	const int consoleWidth = getConsoleWidth();
	const int consoleHeight = getConsoleHeight();
	if ((*entity).m_ix >= 0)
	{
		screenOffsetX = consoleWidth - (*entity).m_ix;
		if (screenOffsetX <= 0)
			(*entity).m_ix = screenOffsetX * -1;
	}
	else
	{
		screenOffsetX = (*entity).m_ix + consoleWidth;
		if (screenOffsetX >= 0)
			(*entity).m_ix = screenOffsetX;
	}
	
	if ((*entity).m_iy >= 0)
	{
		screenOffsetY = consoleHeight - (*entity).m_iy;
		if (screenOffsetY <= 0)
			(*entity).m_iy = screenOffsetY * -1;
	}
	else
	{
		screenOffsetY = (*entity).m_iy + consoleHeight;
		if (screenOffsetY >= 0)
			(*entity).m_iy = screenOffsetY;
	}
}

void spotEntity(TEntity * entity)
{
	gotoxy((*entity).m_ix, (*entity).m_iy);
	hidecursor();
}


/************* 1 *************/
void setMovement1(TEntity * entity)
{
	(*entity).m_ix += 1;
	(*entity).m_iy += 1;
	checkScreenLimits(entity);
}

void paint1(TEntity * entity)
{
	spotEntity(entity);
	printf("1");
}
/*****************************/


/************* 2 *************/
void setMovement2(TEntity * entity)
{
	(*entity).m_ix += 1;
	(*entity).m_iy = (2 * (((*entity).m_iy/2) + 1));
	checkScreenLimits(entity);
}

void paint2(TEntity * entity)
{
	spotEntity(entity);
	printf("2");
}
/*****************************/


/************* 3 *************/
void setMovement3(TEntity * entity)
{
	(*entity).m_ix = (3 * (((*entity).m_ix / 3) + 1));
	(*entity).m_iy += 1;
	checkScreenLimits(entity);
}

void paint3(TEntity * entity)
{
	spotEntity(entity);
	printf("3");
}

/*****************************/


/************* 4 *************/
void setMovement4(TEntity * entity)
{
	(*entity).m_ix += 1;

	if ((*entity).m_iy % 2 == 1 || 0 == (*entity).m_iy)
		(*entity).m_iy += 1;
	else
		(*entity).m_iy -= 1;
	checkScreenLimits(entity);
}

void paint4(TEntity * entity)
{
	spotEntity(entity);
	printf("4");
}
/*****************************/

/************* 5 *************/
void setMovement5(TEntity * entity)
{
	(*entity).m_ix -= 1;
	(*entity).m_iy += 1;
	checkScreenLimits(entity);
}

void paint5(TEntity * entity)
{
	spotEntity(entity);
	printf("5");
}
/*****************************/



int main()
{
	funcEntity functions1[2] = { setMovement1, paint1 };
	TEntity * entity1 = new TEntity(functions1, 0, 0);

	funcEntity functions2[2] = { setMovement2, paint2 };
	TEntity * entity2 = new TEntity(functions2, 0, 0);

	funcEntity functions3[2] = { setMovement3, paint3 };
	TEntity * entity3 = new TEntity(functions3, 0, 0);

	funcEntity functions4[2] = { setMovement4, paint4 };
	TEntity * entity4 = new TEntity(functions4, 0, 0);

	funcEntity functions5[2] = { setMovement5, paint5 };
	TEntity * entity5 = new TEntity(functions5, 0, 0);

	const int sizeT = 5;
	TEntity * tEntities[sizeT] = { entity1, entity2, entity3, entity4, entity5 };

	int x = 0;
	while (x < 500)
	{
		clear();
		for (int i = 0; i < sizeT; i++)
		{

			(*tEntities[i]).m_funcs[0](tEntities[i]);
			(*tEntities[i]).m_funcs[1](tEntities[i]);
		}
		x++;
		Sleep(50);
	}

	delete entity5;
	delete entity4;
	delete entity3;
	delete entity2;
	delete entity1;

	return 0;
}

