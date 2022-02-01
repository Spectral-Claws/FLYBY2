#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <time.h>

#include <impulse.h>
#include <hotas.h>
#include <skyhawk.h>
#include <aurora.h>



/***********************************************************************

  Windows�p�X�N���[���Z�[�o�[�X�P���g��

  ���ӓ_
  (1)�f�[�^�t�@�C�����K�v�ȂƂ��� c:\\windows\\???? �̂悤�ɁA�t���p�X
     �Ŏw�肷��B
  (2)BiLoad??? �̑���� ArLoad??? ���g���B
  (3)ArLoad??? �œǂݍ��񂾃I�u�W�F�N�g�́AScSvTerminate�֐��̒��ŕK��
     ArFree??? �Ń��������������B
  (4)�v���W�F�N�g���[�N�X�y�[�X�́Avc40_s.mdp,vc40_s.mak ���g���B
     (VC++ 4.0��p)

***********************************************************************/


int PrintFunc(char *str);

#define BIWORKSIZE 0x20000L
char BiWork[BIWORKSIZE];


void ScSvInitialize(void)
{
	BIPROJ prj;

	BiMemoryInitialize();
	BiCalcInitialize();
	BiGraphInitialize(BiWork,BIWORKSIZE);
	BiDeviceInitialize();

	BiSetWindowName("Screen Saver Skeleton");
	BiOpenWindow(640,480);

	BiGetStdProjection(&prj);
	BiSetProjection(&prj);
	BiSetShadMode(BI_ON);

	HtInitialize();

	ArInitialize();

	SkSetPrintFunc(PrintFunc);
}

void ScSvMain(void)
{
	/* Main Procedure Here */
}

void ScSvTerminate(void)
{
	/* Free All Allocated Memory Here */
	BiCloseWindow();
}

int PrintFunc(char *str)
{
	HtMessageBox(str,NULL);
	return 0;
}
