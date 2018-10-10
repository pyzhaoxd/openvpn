/*
 *  openvpnmsica -- Custom Action DLL to provide OpenVPN-specific support to MSI packages
 *
 *  Copyright (C) 2018 Simon Rozman <simon@rozman.si>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2
 *  as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef MSICA_H
#define MSICA_H

#include <windows.h>
#include <msi.h>
#include "../tapctl/basic.h"


 /*
  * Error codes (next unused 2552L)
  */
#define ERROR_MSICA       2550L
#define ERROR_MSICA_ERRNO 2551L


/**
 * TLS data
 */
struct openvpnmsica_tls_data
{
    MSIHANDLE hInstall; /** Handle to the installation session. */
};


/**
 * MSI session handle TLS index
 */
extern DWORD openvpnmsica_tlsidx_session;


/*
 * Exported DLL Functions
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Find existing TAP interfaces and set TAPINTERFACES property with semicolon delimited list
 * of installed TAP interface GUIDs.
 *
 * @param hInstall      Handle to the installation provided to the DLL custom action
 *
 * @return ERROR_SUCCESS on success; An error code otherwise
 *         See: https://msdn.microsoft.com/en-us/library/windows/desktop/aa368072.aspx
 */
__declspec(dllexport) UINT __stdcall
FindTAPInterfaces(_In_ MSIHANDLE hInstall);


/**
 * Evaluate the TAPInterface table of the MSI package database and prepare a list of TAP
 * interfaces to install/remove.
 *
 * @param hInstall      Handle to the installation provided to the DLL custom action
 *
 * @return ERROR_SUCCESS on success; An error code otherwise
 *         See: https://msdn.microsoft.com/en-us/library/windows/desktop/aa368072.aspx
 */
__declspec(dllexport) UINT __stdcall
EvaluateTAPInterfaces(_In_ MSIHANDLE hInstall);


/**
 * Perform scheduled deferred action.
 *
 * @param hInstall      Handle to the installation provided to the DLL custom action
 *
 * @return ERROR_SUCCESS on success; An error code otherwise
 *         See: https://msdn.microsoft.com/en-us/library/windows/desktop/aa368072.aspx
 */
__declspec(dllexport) UINT __stdcall
ProcessDeferredAction(_In_ MSIHANDLE hInstall);

#ifdef __cplusplus
}
#endif

#endif
