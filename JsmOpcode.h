#ifndef JSMOPCODE_H
#define JSMOPCODE_H

#include <QtCore>

class JsmOpcode
{
public:
	enum Opcode {
		NOP,
		CAL,
		JMP,
		JPF,
		GJMP,
		LBL,
		RET,
		PSHN_L,
		PSHI_L,
		POPI_L,
		PSHM_B,
		POPM_B,
		PSHM_W,
		POPM_W,
		PSHM_L,
		POPM_L,
		PSHSM_B,
		PSHSM_W,
		PSHSM_L,
		PSHAC,
		REQ,
		REQSW,
		REQEW,
		PREQ,
		PREQSW,
		PREQEW,
		UNUSE,
		DEBUG,
		HALT,
		SET,
		SET3,
		IDLOCK,
		IDUNLOCK,
		EFFECTPLAY2,
		FOOTSTEP,
		JUMP,
		JUMP3,
		LADDERUP,
		LADDERDOWN,
		LADDERUP2,
		LADDERDOWN2,
		MAPJUMP,
		MAPJUMP3,
		SETMODEL,
		BASEANIME,
		ANIME,
		ANIMEKEEP,
		CANIME,
		CANIMEKEEP,
		RANIME,
		RANIMEKEEP,
		RCANIME,
		RCANIMEKEEP,
		RANIMELOOP,
		RCANIMELOOP,
		LADDERANIME,
		DISCJUMP,
		SETLINE,
		LINEON,
		LINEOFF,
		WAIT,
		MSPEED,
		MOVE,
		MOVEA,
		PMOVEA,
		CMOVE,
		FMOVE,
		PJUMPA,
		ANIMESYNC,
		ANIMESTOP,
		MESW,
		MES,
		MESSYNC,
		MESVAR,
		ASK,
		WINSIZE,
		WINCLOSE,
		UCON,
		UCOFF,
		MOVIE,
		MOVIESYNC,
		SETPC,
		DIR,
		DIRP,
		DIRA,
		PDIRA,
		SPUREADY,
		TALKON,
		TALKOFF,
		PUSHON,
		PUSHOFF,
		ISTOUCH,
		MAPJUMPO,
		MAPJUMPON,
		MAPJUMPOFF,
		SETMESSPEED,
		SHOW,
		HIDE,
		TALKRADIUS,
		PUSHRADIUS,
		AMESW,
		AMES,
		GETINFO,
		THROUGHON,
		THROUGHOFF,
		BATTLE,
		BATTLERESULT,
		BATTLEON,
		BATTLEOFF,
		KEYSCAN,
		KEYON,
		AASK,
		PGETINFO,
		DSCROLL,
		LSCROLL,
		CSCROLL,
		DSCROLLA,
		LSCROLLA,
		CSCROLLA,
		SCROLLSYNC,
		RMOVE,
		RMOVEA,
		RPMOVEA,
		RCMOVE,
		RFMOVE,
		MOVESYNC,
		CLEAR,
		DSCROLLP,
		LSCROLLP,
		CSCROLLP,
		LTURNR,
		LTURNL,
		CTURNR,
		CTURNL,
		ADDPARTY,
		SUBPARTY,
		CHANGEPARTY,
		REFRESHPARTY,
		SETPARTY,
		ISPARTY,
		ADDMEMBER,
		SUBMEMBER,
		ISMEMBER,
		LTURN,
		CTURN,
		PLTURN,
		PCTURN,
		JOIN,
		MESFORCUS,
		BGANIME,
		RBGANIME,
		RBGANIMELOOP,
		BGANIMESYNC,
		BGDRAW,
		BGOFF,
		BGANIMESPEED,
		SETTIMER,
		DISPTIMER,
		SHADETIMER,
		SETGETA,
		SETROOTTRANS,
		SETVIBRATE,
		STOPVIBRATE,
		MOVIEREADY,
		GETTIMER,
		FADEIN,
		FADEOUT,
		FADESYNC,
		SHAKE,
		SHAKEOFF,
		FADEBLACK,
		FOLLOWOFF,
		FOLLOWON,
		GAMEOVER,
		ENDING,
		SHADELEVEL,
		SHADEFORM,
		FMOVEA,
		FMOVEP,
		SHADESET,
		MUSICCHANGE,
		MUSICLOAD,
		FADENONE,
		POLYCOLOR,
		POLYCOLORALL,
		KILLTIMER,
		CROSSMUSIC,
		DUALMUSIC,
		EFFECTPLAY,
		EFFECTLOAD,
		LOADSYNC,
		MUSICSTOP,
		MUSICVOL,
		MUSICVOLTRANS,
		MUSICVOLFADE,
		ALLSEVOL,
		ALLSEVOLTRANS,
		ALLSEPOS,
		ALLSEPOSTRANS,
		SEVOL,
		SEVOLTRANS,
		SEPOS,
		SEPOSTRANS,
		SETBATTLEMUSIC,
		BATTLEMODE,
		SESTOP,
		BGANIMEFLAG,
		INITSOUND,
		BGSHADE,
		BGSHADESTOP,
		RBGSHADELOOP,
		DSCROLL2,
		LSCROLL2,
		CSCROLL2,
		DSCROLLA2,
		LSCROLLA2,
		CSCROLLA2,
		DSCROLLP2,
		LSCROLLP2,
		CSCROLLP2,
		SCROLLSYNC2,
		SCROLLMODE2,
		MENUENABLE,
		MENUDISABLE,
		FOOTSTEPON,
		FOOTSTEPOFF,
		FOOTSTEPOFFALL,
		FOOTSTEPCUT,
		PREMAPJUMP,
		USE,
		SPLIT,
		ANIMESPEED,
		RND,
		DCOLADD,
		DCOLSUB,
		TCOLADD,
		TCOLSUB,
		FCOLADD,
		FCOLSUB,
		COLSYNC,
		DOFFSET,
		LOFFSETS,
		COFFSETS,
		LOFFSET,
		COFFSET,
		OFFSETSYNC,
		RUNENABLE,
		RUNDISABLE,
		MAPFADEOFF,
		MAPFADEON,
		INITTRACE,
		SETDRESS,
		GETDRESS,
		FACEDIR,
		FACEDIRA,
		FACEDIRP,
		FACEDIRLIMIT,
		FACEDIROFF,
		SARALYOFF,
		SARALYON,
		SARALYDISPOFF,
		SARALYDISPON,
		MESMODE,
		FACEDIRINIT,
		FACEDIRI,
		JUNCTION,
		SETCAMERA,
		BATTLECUT,
		FOOTSTEPCOPY,
		WORLDMAPJUMP,
		RFACEDIRI,
		RFACEDIR,
		RFACEDIRA,
		RFACEDIRP,
		RFACEDIROFF,
		FACEDIRSYNC,
		COPYINFO,
		PCOPYINFO,
		RAMESW,
		BGSHADEOFF,
		AXIS,
		AXISSYNC,
		MENUNORMAL,
		MENUPHS,
		BGCLEAR,
		GETPARTY,
		MENUSHOP,
		DISC,
		DSCROLL3,
		LSCROLL3,
		CSCROLL3,
		MACCEL,
		MLIMIT,
		ADDITEM,
		SETWITCH,
		SETODIN,
		RESETGF,
		MENUNAME,
		REST,
		MOVECANCEL,
		PMOVECANCEL,
		ACTORMODE,
		MENUSAVE,
		SAVEENABLE,
		PHSENABLE,
		HOLD,
		MOVIECUT,
		SETPLACE,
		SETDCAMERA,
		CHOICEMUSIC,
		GETCARD,
		DRAWPOINT,
		PHSPOWER,
		KEY,
		CARDGAME,
		SETBAR,
		DISPBAR,
		KILLBAR,
		SCROLLRATIO2,
		WHOAMI,
		MUSICSTATUS,
		MUSICREPLAY,
		DOORLINEOFF,
		DOORLINEON,
		MUSICSKIP,
		DYING,
		SETHP,
		GETHP,
		MOVEFLUSH,
		MUSICVOLSYNC,
		PUSHANIME,
		POPANIME,
		KEYSCAN2,
		KEYON2,
		PARTICLEON,
		PARTICLEOFF,
		KEYSIGHNCHANGE,
		ADDGIL,
		ADDPASTGIL,
		ADDSEEDLEVEL,
		PARTICLESET,
		SETDRAWPOINT,
		MENUTIPS,
		LASTIN,
		LASTOUT,
		SEALEDOFF,
		MENUTUTO,
		OPENEYES,
		CLOSEEYES,
		BLINKEYES,
		SETCARD,
		HOWMANYCARD,
		WHERECARD,
		ADDMAGIC,
		SWAP,
		SETPARTY2,
		SPUSYNC,
		BROKEN,
		Unknown1,
		Unknown2,
		Unknown3,
		Unknown4,
		Unknown5,
		Unknown6,
		Unknown7,
		Unknown8,
		Unknown9,
		Unknown10,
		Unknown11,
		Unknown12,
		Unknown13,
		Unknown14,
		Unknown15,
		Unknown16,
		Unknown17,
		Unknown18
	};

	JsmOpcode();
	JsmOpcode(quint32 op);
	JsmOpcode(unsigned int key, int param);
	unsigned int key() const;
	int param() const;
	quint32 opcode() const;
	void setOpcode(quint32 op);
	void setKey(unsigned int key);
	void setParam(int param);
	virtual bool hasParam() const;
	virtual int popCount() const;
	virtual int pushCount() const;
	virtual QString name() const;
	virtual QString paramStr() const;
	virtual QString desc() const;

	static const char *opcodes[376];
private:
	quint32 op;
};

class JsmOpcodeCal : public JsmOpcode
{
public:
	JsmOpcodeCal(quint32 op);
	JsmOpcodeCal(unsigned int key, int param);
	virtual bool hasParam() const;
	virtual int popCount() const;
	virtual int pushCount() const;
	virtual QString paramStr() const;
	static const char *cal_table[15];
};

class JsmOpcodePsh : public JsmOpcode
{
public:
	JsmOpcodePsh(quint32 op);
	JsmOpcodePsh(unsigned int key, int param);
	virtual bool hasParam() const;
	virtual int popCount() const;
	virtual int pushCount() const;
};

class JsmOpcodePop : public JsmOpcode
{
public:
	JsmOpcodePop(quint32 op);
	JsmOpcodePop(unsigned int key, int param);
	virtual bool hasParam() const;
	virtual int popCount() const;
	virtual int pushCount() const;
};

#endif // JSMOPCODE_H
