// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIexpdImu2edIappdIusersdIaboldydIAnaDirdISimulationTestingFall25dIAnalysisCodedIPlotsdIMDC2020badIMCParticlesTestdICeEndpointdIdOdIdOdOdIdOdOdIdOdOdIdOdOdIplotElectronMomHist_C_ACLiC_dict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "/exp/mu2e/app/users/aboldy/AnaDir/SimulationTestingFall25/AnalysisCode/Plots/MDC2020ba/MCParticlesTest/CeEndpoint/./../../../../plotElectronMomHist.C"

// Header files passed via #pragma extra_include

namespace {
  void TriggerDictionaryInitialization_plotElectronMomHist_C_ACLiC_dict_Impl() {
    static const char* headers[] = {
"./../../../../plotElectronMomHist.C",
nullptr
    };
    static const char* includePaths[] = {
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/opt/spack/linux-almalinux9-x86_64_v2/gcc-13.3.0/root-6.32.06-oxcmy6p7yuy2lptemnwcizm3fov6fugi/include/root",
"/cvmfs/mu2e.opensciencegrid.org/Musings/EventNtuple/v06_07_00",
"/cvmfs/mu2e.opensciencegrid.org/Musings/SimJob/MDC2020bc",
"/cvmfs/mu2e.opensciencegrid.org/Musings/Offline/v10_48_00",
"/cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/var/spack/environments/muse-al9-prof-e29-p084/.spack-env/view/include/KinKal/Examples",
"/cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/var/spack/environments/muse-al9-prof-e29-p084/.spack-env/view/include/KinKal/Trajectory",
"/cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/var/spack/environments/muse-al9-prof-e29-p084/.spack-env/view/include/KinKal/General",
"/cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/var/spack/environments/muse-al9-prof-e29-p084/.spack-env/view/include",
"/cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/var/spack/environments/muse-al9-prof-e29-p084/.spack-env/view/src",
"/usr/include",
"/cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/var/spack/environments/muse-al9-prof-e29-p084/.spack-env/view/include/KinKal/General",
"/cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/var/spack/environments/muse-al9-prof-e29-p084/.spack-env/view/include/KinKal/Examples",
"/cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/var/spack/environments/muse-al9-prof-e29-p084/.spack-env/view/include/KinKal/Trajectory",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/opt/spack/linux-almalinux9-x86_64_v2/gcc-13.3.0/root-6.32.06-oxcmy6p7yuy2lptemnwcizm3fov6fugi/etc/root",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/opt/spack/linux-almalinux9-x86_64_v2/gcc-13.3.0/root-6.32.06-oxcmy6p7yuy2lptemnwcizm3fov6fugi/etc/root/cling",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/opt/spack/linux-almalinux9-x86_64_v2/gcc-13.3.0/root-6.32.06-oxcmy6p7yuy2lptemnwcizm3fov6fugi/etc/root/cling/plugins/include",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/opt/spack/linux-almalinux9-x86_64_v2/gcc-13.3.0/root-6.32.06-oxcmy6p7yuy2lptemnwcizm3fov6fugi/include/root",
"/cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/var/spack/environments/muse-al9-prof-e29-p084/.spack-env/view/tbb/2022.0/include",
"/cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/opt/spack/linux-almalinux9-x86_64_v2/gcc-13.3.0/root-6.32.06-oxcmy6p7yuy2lptemnwcizm3fov6fugi/include",
"/scratch/workspace/SE-915/label1/gcc-11/tmp/jenkins/spack-stage/spack-stage-root-6.32.06-oxcmy6p7yuy2lptemnwcizm3fov6fugi/spack-build-oxcmy6p/include",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/opt/spack/linux-almalinux9-x86_64_v2/gcc-11.5.0/xz-5.4.6-jnjqwcdc2a5qmdvgpvuys5jsfew7diof/include",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/opt/spack/linux-almalinux9-x86_64_v2/gcc-11.5.0/zstd-1.5.6-2twrs5fo3fodypntgwnp6ullxnm77iyz/include",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/opt/spack/linux-almalinux9-x86_64_v2/gcc-11.5.0/xxhash-0.8.2-yiumq7hucwd46zco7dicluamgxp7gmta/include",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/opt/spack/linux-almalinux9-x86_64_v2/gcc-11.5.0/lz4-1.10.0-jp5vjpbqessfqsgk4i3lxh3qc2y7hcwg/include",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/opt/spack/linux-almalinux9-x86_64_v2/gcc-11.5.0/intel-oneapi-tbb-2022.0.0-f2ig6qbzgihk3hlxl4z3wvbjp7chos2n/tbb/2022.0/include",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/opt/spack/linux-almalinux9-x86_64_v2/gcc-11.5.0/nlohmann-json-3.11.3-mjygsthp7riu7c2ouspcntwcimrtkczw/include",
"/scratch/workspace/SE-915/label1/gcc-11/tmp/jenkins/spack-stage/spack-stage-root-6.32.06-oxcmy6p7yuy2lptemnwcizm3fov6fugi/spack-build-oxcmy6p/include/",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cvmfs/mu2e.opensciencegrid.org/spackages/241207/spack/opt/spack/linux-almalinux9-x86_64_v2/gcc-13.3.0/root-6.32.06-oxcmy6p7yuy2lptemnwcizm3fov6fugi/include/root",
"/exp/mu2e/app/users/aboldy/AnaDir/SimulationTestingFall25/AnalysisCode/Plots/MDC2020ba/MCParticlesTest/CeEndpoint/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "plotElectronMomHist_C_ACLiC_dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "plotElectronMomHist_C_ACLiC_dict dictionary payload"

#ifndef __ACLIC__
  #define __ACLIC__ 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "./../../../../plotElectronMomHist.C"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"plotElectronMomHist", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("plotElectronMomHist_C_ACLiC_dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_plotElectronMomHist_C_ACLiC_dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_plotElectronMomHist_C_ACLiC_dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_plotElectronMomHist_C_ACLiC_dict() {
  TriggerDictionaryInitialization_plotElectronMomHist_C_ACLiC_dict_Impl();
}
