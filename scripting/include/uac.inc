#if defined _uac_included
	#endinput
#endif

#define _uac_included

#pragma reqlib UAC
#if !defined AMXMODX_NOAUTOLOAD
	#pragma loadlib UAC
#endif

#include <uac_consts>
#include <uac_version>

forward UAC_Loading();
forward UAC_Loaded();
forward UAC_Checking(const id);
forward UAC_Checked(const id, const UAC_CheckResult:result);
forward UAC_Pushing();
forward UAC_Pushed();

native bool:UAC_Reload();
native bool:UAC_StartLoad();
native bool:UAC_FinishLoad();
native bool:UAC_Push(const id, const authid[], const password[], const access, const flags, const prefix[], const expired, const otpions);
native UAC_GetSource();
native UAC_GetId();
native UAC_GetAccess();
native UAC_GetFlags();
native UAC_GetPassword(dest[], const length);
native UAC_GetPrefix(dest[], const length);
native UAC_GetExpired();
native UAC_GetOptions();
native bool:UAC_SetAccess(const access);
native UAC_CheckPlayer(id);
native bool:UAC_IterReset();
native bool:UAC_IterEnded();
native bool:UAC_IterNext();
native UAC_GetPlayerPrivilege(const player);
native UAC_GetPlayerExpired(const player);

/*
* This is callback from GMX Core that gives major/minor versions for verifying compatibility for GMX versions.
* Do not modify this!
*/
public __uac_version_check(const majorVersion, const minorVersion) {
	if(majorVersion != UAC_MAJOR_VERSION) {
		set_fail_state("Api major version mismatch; expected %d, real %d", UAC_MAJOR_VERSION, majorVersion);
		return;
	}

	if(minorVersion < UAC_MINOR_VERSION){
		set_fail_state("Api minor version mismatch; expected at least %d, real %d", UAC_MINOR_VERSION, minorVersion);
		return;
	}
}
