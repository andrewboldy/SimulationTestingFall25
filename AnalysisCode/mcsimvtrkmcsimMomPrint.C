//----------------------------------------------------------------------------------

//mcsimvtrkmcsimMomPrint(string filelist)
//Written by Andrew Boldy
//University of South Carolina
//Fall 2025

//----------------------------------------------------------------------------------

//Plots the electron momentum for a given non-mixed filelist in a histogram specifically using the MCParticles structure to determine if there are differences between this and
//the trkmcsim branch.
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

void mcsimvtrkmcsimMomPrint(const string &filelist)
{

  //Initialize the histograms
  TH1F* electronMCSimMomHist = new TH1F("electronMCSimMomHist", "Electron Momentum in MCSim (MeV/c)", 50, 10, 130);
  TH1F* electronTrkMCSimMomHist = new TH1F("electronTrkMCSimMomHist", "Electron Momentum in TrkMCSim (MeV/c)", 50, 10, 130);

  //Open up the file and check the number of entries:
  RooUtil util(filelist);
  int numEvents = util.GetNEvents();
  //int numEvents = 20;
  cout << "The filelist: " << filelist << endl;
  cout << "Number of events in filelist: " << numEvents << endl;

  
  ifstream listOfFiles(filelist);
  int fileCount = 0;
  string line;
  while (getline(listOfFiles,line))
  {
    if (!line.empty())
    {
      fileCount++;
    }
  }
  cout << " " << endl;
  //Check the outputs via printing
  cout << "Beginning the analysis of the file list using mcsim." << endl;
  for (int i_event = 0; i_event < numEvents; i_event++)
  {
    cout << "Event number: " << i_event << endl;
    auto& eventA = util.GetEvent(i_event);
    auto e_minus_tracksA = eventA.GetTracks(is_e_minus);
    for (auto& track : e_minus_tracksA)
    {
      auto all_particles = track.GetMCParticles();
      for (auto& particle : all_particles)
      {
        if (particle.mcsim->pdg == 11)
        {
          cout << "Momentum for particle in event number  " <<i_event << ": "  << particle.mcsim->mom.R() << " MeV/c." << endl;
        }
      }
    }
  }
  cout << " " << endl;
  cout << "Beginning the analysis of the file list using trkmcsim." << endl;
  for (int j_event = 0; j_event < numEvents; j_event++)
  {
    cout << "Event number: " << j_event << endl;
    auto& eventB = util.GetEvent(j_event);
    auto e_minus_tracksB = eventB.GetTracks(is_e_minus);
    for (auto& track : e_minus_tracksB)
    {
      if (track.trkmcsim != nullptr)
      {
        for (const auto& mctrack : *(track.trkmcsim))
        {
          if (mctrack.pdg == 11)
          {
            cout << "Momentum for particle in event number " << j_event << ": " << mctrack.mom.R() << " MeV/c." << endl;
          }
        }
      }
    }
  }
}

