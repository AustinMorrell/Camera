#include "Runit.h"

float previousTime = 0;

int main()
{
	Runit* DatProgram = new App();
	if (DatProgram->Start() > 0)
	{
		while (DatProgram->Update() == true)
		{
			DatProgram->Draw();
		}
		DatProgram->Stop();
	}
	delete DatProgram;
	return 0;
}