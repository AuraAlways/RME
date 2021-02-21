## RME Exploit
-----------------------------------
Theatre Infections / RME [X360]

Provided By Aura / Kyle

OnyxAPI.Online

Still On The 360 lol?
-----------------------------------

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

Select Release_LCTG if you are on Debug

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
Here You Can Find Some Offsets

Multiplayer

Stat Entry: 0x840C0500

Kills: 0x84348D00

Deaths: 0x84348AD2

Kill Steak(s): 0x84348FE8

Hits: 0x84348A45

Prestige: 0x843491A4

XP/Level: 0x843491BC

Misses: 0x843492CA

Games Played: 0x83583941

Head Shots: 0x839ADBB1

Looses: 0x84348D72

Score: 0x843491E0

Total Shots: 0x839ADC06

Time Played: 0x8434929A

Win/Loss Ratio: 0x839ADC0A

Prestige Tokens - 0x8435292E

Wins: 0x843492E2

Win Streak(s): 0x835839A3

Unlock Entry Titles: 0x8435429F

Unlock Entry Weapons: 0x8434AF80


Class 1:

Primary = 0x84353A4A

Secondary = 0x84353A58

Primary Camo = 0x84353A50

Secondary Camo = 0x84353A5D

Perk 1 = 0x84353A66

Perk 2 = 0x84353A67

Perk3 = 0x84353A68

Lethal = 0x84353A6C

Tatical = 0x84353A6D


Class 2:

Primary = 0x84353A7E

Secondary = 0x84353A8C

Primary Camo = 0x84353A83

Secondary Camo = 0x84353A92

Perk 1 = 0x84353A9A

Perk 2 = 0x84353A9B

Perk3 = 0x84353A9C

Lethal = 0x84353AA0

Tatical = 0x84353AA1


Class 3:

Primary = 0x84353AB2

Secondary = 0x84353AC1

Primary Camo = 0x84353AB9

Secondary Camo = 0x84353AC6

Perk 1 = 0x84353ACF

Perk 2 = 0x84353AD0

Perk3 = 0x84353AD1

Lethal = 0x84353AD5

Tatical = 0x84353AD6

Class 4:

Primary = 0x84353AE7

Secondary = 0x84353AF5

Primary Camo = 0x84353AED

Secondary Camo = 0x84353AFB

Perk 1 = 0x84353B03

Perk 2 = 0x84353B04

Perk3 = 0x84353B05

Lethal = 0x84353B09

Tatical = 0x84353B0C

Class 5:

Primary = 0x84353B1C

Secondary = 0x84353B2A

Primary Camo = 0x84353B22

Secondary Camo = 0x84353B30

Perk 1 = 0x84353B38

Perk 2 = 0x84353B39

Perk3 = 0x84353B3A

Lethal = 0x84353B3E

Tatical = 0x84353B40

Class 6:

Primary = 0x84353B50

Secondary = 0x84353B5E

Primary Camo = 0x84353B56

Secondary Camo = 0x84353B64

Perk 1 = 0x84353B6C

Perk 2 = 0x84353B6D

Perk3 = 0x84353B6E

Lethal = 0x84353B72

Tatical = 0x84353B75

Class 7:

Primary = 0x84353B85

Secondary = 0x84353B93

Primary Camo = 0x84353B8B

Secondary Camo = 0x84353B99

Perk 1 = 0x84353BA1

Perk 2 = 0x84353BA2

Perk3 = 0x84353BA3

Lethal = 0x84353BA7

Tatical = 0x84353BA9

Class 8:

Primary = 0x84353BB9

Secondary = 0x84353BC7

Primary Camo = 0x84353BBF

Secondary Camo = 0x84353BCD

Perk 1 = 0x84353BD5

Perk 2 = 0x84353BD6

Perk3 = 0x84353BD7

Lethal = 0x84353BDB

Tatical = 0x84353BDE

Class 9:

Primary = 0x84353BEE

Secondary = 0x84353BFC

Primary Camo = 0x84353BF4

Secondary Camo = 0x84353C02,

Perk 1 = 0x84353C0A

Perk 2 = 0x84353C0B

Perk3 = 0x84353C0C

Lethal = 0x84353C10

Tatical = 0x84353C12

Class 10:

Primary = 0x84353C22

Secondary = 0x84353C30

Primary Camo = 0x84353C28

Secondary Camo = 0x84353C36

Perk 1 = 0x84353C3E

Perk 2 = 0x84353C3F

Perk3 = 0x84353C40

Lethal = 0x84353C44

Tatical = 0x84353C47

Zombies

Stat Entry: 0x843489C8

Bullets Total: 0x84348AD0

Miles Traveled: 0x84348ACC

Perks: 0x84348AA8

Revives: 0x84348AA4

XP: 0x84348C00

Kills: 0x84348A9C

Deaths: 0x84348AD8

Head Shots: 0x84348A14

Doors: 0x84348AC8

Points: 0x83551A10 + 0x55C8

Ammo 1: 0x83551A10 + 0x428

Ammo 2: 0x83551A10 + 0x42C

Ammo 3: 0x83551A10 + 0x430

Ammo 4: 0x83551A10 + 0x434

Ammo 5: 0x83551A10 + 0x438

Ammo 6: 0x83551A10 + 0x43C

