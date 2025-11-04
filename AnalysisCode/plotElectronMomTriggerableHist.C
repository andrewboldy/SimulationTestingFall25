//----------------------------------------------------------------------------------

//plotElectronMomTriggerableHist(string filelist)
//Written by Andrew Boldy
//University of South Carolina
//Fall 2025

//----------------------------------------------------------------------------------

//Plots the electron momentum for a given non-mixed filelist in a histogram.
//Must be run using C++ so compile mode in order to rectify issues that are generated when using common_cuts.hh

//----------------------------------------------------------------------------------

//My Inclusions

//Standard Inclusions
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

//CERN ROOT Inclusions
#include <TCanvas.h>
#include <TH1F.h>
#include <TLegend.h>

//Mu2e Inclusions
#include "EventNtuple/rooutil/inc/RooUtil.hh"
#include "EventNtuple/rooutil/inc/common_cuts.hh"

//Personal Inclusions (if any)

//Namespace
using namespace std;

void plotElectronMomTriggerableHist(const string &triggerableFilelist)
{
  //Initilizing the histograms and the TCanvas
  TCanvas* c1 = new TCanvas("c1","c1");
  TH1F* eMinusTriggerableStartMomHist = new TH1F("eMinusTriggerableStartMomHist", "eMinus Start Momentum (Triggerable)", 50, 10, 110);
  eMinusTriggerableStartMomHist->GetXaxis()->SetTitle("Start Momentum (MeV/c)");
  eMinusTriggerableStartMomHist->GetYaxis()->SetTitle("Counts");
  eMinusTriggerableStartMomHist->SetStats(0);
  
  cout << "Beginning the analysis of the triggerable files." << endl;
  ifstream listOfFilesB(triggerableFilelist);
  int triggerableFileCount = 0;
  string lineB;
  while (getline(listOfFilesB,lineB))
  {
    if (!lineB.empty())
    {
      triggerableFileCount++;
    }
  }
  cout << "The triggerable filelist has: " << triggerableFileCount << " files stored in it." << endl;

  RooUtil triggerableUtil(triggerableFilelist);
  int numTriggerableEvents = triggerableUtil.GetNEvents();
  cout << "This triggerable filelist has " << numTriggerableEvents << " events." << endl;

  for (int j_event = 0; j_event < numTriggerableEvents; j_event++)
  {
    auto& event = triggerableUtil.GetEvent(j_event);
    auto e_minus_tracks = event.GetTracks(is_e_minus);
    for (auto& track : e_minus_tracks)
    {
        if (track.trkmcsim != nullptr)
        {
          for (const auto& mctrack : *(track.trkmcsim))
          {
            if (mctrack.pdg == 11)
            {
              eMinusTriggerableStartMomHist->Fill(mctrack.mom.R());
            }
          }
        }
     }
  }

cout << "Creating and saving histogram." << endl;
eMinusTriggerableStartMomHist->Draw();
c1->SaveAs("eMinusTriggerableStartMomHist.pdf");
c1->Clear();
}
