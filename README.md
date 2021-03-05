Requirements:

Visual Studio 2010 Ultimate

Xbox 360 SDK Full Installation 

Module Injector

--------------------------------------------------------------------------------

Setting Up:

Go Into "DllMain.cpp

Scroll Until You See "void R_EndFrame()"

This Is Under "void SendDataRME(int address, intvalue) {"

You Will See 

SendDataRME(0x843491A4, 16777216); // Prestige 1

0x843491A4 = Prestige Offset

16777216 = Prestige 1

Below You Can See Mutiple Hexadecimal and Decimal Values For Prestige 1-15 Inclduing 69 420 1337

If You Wanted To Infect Whoever Watches Your Clip To Prestige 69 You Would Replace Or Add

SendDataRME(0x843491A4, 1157627904); // Prestige 69

If We Wanted To "Print A Message" In Center Screen We Would Use

SV_SendServerCommand(0, 1, va("< \"^5Stop The Clip Here If You Want To Be Prestige 69"));

If We Wanted To "Print A Message" In The Killfeed We Would Use

SV_SendServerCommand(0, 1, va("O \"^2Stop The Clip Here If You Want To Be Prestige 69"));

---------------------------------------------------------------------------------------------------

Prestige 1 = 16777216 / 0x1000000

Prestige 2 = 33554432 / 0x2000000

Prestige 3 = 50331648 / 0x3000000

Prestige 4 = 67108864 / 0x4000000

Prestige 5 = 83886080 / 0x5000000

Prestige 6 = 100663296 / 0x6000000

Prestige 7 = 117440512 / 0x7000000

Prestige 8 = 134217728 / 0x8000000

Prestige 9 = 150994944 / 0x9000000

Prestige 10 = 167772160 / 0xA000000

Prestige 11 = 184549376 / 0xB000000

Prestige 12 = 201326592 / 0xC000000

Prestige 13 = 218103808 / 0xD000000

Prestige 14 = 234881024 / 0xE000000

Prestige 15 = 251658240 / 0xF000000

Prestige 69 = 1157627904 / 0x45000000

Prestige 420 = 7046430720 / 0x1A4000000

Prestige 1337 = 22431137792 / 0x539000000

-----------------------------------------------------------------------------------------------------

Building The "XeX"

Select Release_LTCG if you are on Debug

And Hit The Green |>

The Compiled Build We Be In A Folder Named Release_LCTG in the same location as "DllMain.cpp"

-----------------------------------------------------------------------------------------------------

Executing The Infection:

Load Up Black Ops II  > Custom Games

Game Recording ON

Start The Game Use The Provdied Module Loader Or Your Stealths To Inject The XeX "RME.xex" (Make Sure Its On The Root Of Your 360's HDD)

If You Outputted "A Message Center Or Killfeed" You Will Know Once Its Done (Legit Takes Less Than 1 Second)

-----------------------------------------------------------------------------------------------------

Can I Do More Than Prestige Infections

You Can Do Custom Camo Infections GSC Infections So On...

A Example Of GSC And Kill's Would Be

SendDataRME(0x84348D00, 1337); // Kills

----------------------------------------------

GSC Infection Example

GSC Pointer Addresses

https://pastebin.com/raw/Drpy1A4b

----------------------------------------------
#define GSC_Pointer 0x00000 // GSC Pointer

#define fileSize 0x1111 // Size Of THE GSC File
		```
void R_EndFrame()
{
	if (!Dvar_GetBool("cl_ingame")) 
		return;
	if (GSC_Pointer < 1)
		return;

	if (!done)
	{
		SendDataRME(0x40300000 + shift, *(int*)(0x40300000 + shift));
	}
	if (shift > fileSize) {
		shift = fileSize;
		done = true;
		if (done) {
			SV_SendServerCommand(0, 1, va("O \"^1--- ^5DONE ^1---"));
			SendDataRME(GSC_Pointer, 0x40300000);
			unload = true;
			if (unload)
				R_EndFrameDetour.TakeDownDetour();
		}
	}
	else
                SV_SendServerCommand(0, 1, va("O \"^5Infecting ^6Hax"));
		shift += 4;
                SV_SendServerCommand(0, 1, va("< \"^5BO2 ^6Dead"));
	        R_EndFrameDetour.CallOriginal();
		}

----------------------------------------------
