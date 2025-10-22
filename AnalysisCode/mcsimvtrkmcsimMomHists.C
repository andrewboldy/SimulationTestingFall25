//----------------------------------------------------------------------------------

//mcsimvtrkmcsimMomHists(string filelist)
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

void mcsimvtrkmcsimMomHists(const string &filelist)
{

  //Initialize the canvas and histograms
  TCanvas* c1 = new TCanvas("c1","c1");
  TH1F* electronMCSimMomHist = new TH1F("electronMCSimMomHist", "Electron Momentum in MCSim (MeV/c)",50,10,130);
  TH1F* electronTrkMCSimMomHist = new TH1F("electronTrkMCSimMomHist", "Electron Momentum in TrkMCSim (MeV/c)",50,10,130);

  //Open up the file and check the number of entries:
  RooUtil util(filelist);
  int numEvents = util.GetNEvents();
  //int numEvents = 10;
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
  cout << "Beginning the analysis of the file list using mcsim." << endl;
  //Check the outputs via printing
  for (int i_event = 0; i_event < numEvents; i_event++)
  {
    auto& eventA = util.GetEvent(i_event);
    auto e_minus_tracksA = eventA.GetTracks(is_e_minus);
    for (auto& track : e_minus_tracksA)
    {
      auto all_particles = track.GetMCParticles();
      for (auto& particle : all_particles)
      {
        if (particle.mcsim->pdg == 11)
        {
          electronMCSimMomHist->Fill(particle.mcsim->mom.R());
        }
      }
    }
  }
  cout << " " << endl;
  cout << "Beginning the analysis of the file list using trkmcsim." << endl;
  for (int j_event = 0; j_event < numEvents; j_event++)
  {
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
            electronTrkMCSimMomHist->Fill(mctrack.mom.R());
          }
        }
      }
    }
  }
  cout << "Creating the histogram plotting mcsim and trkmcsim momenta." << endl;
  electronMCSimMomHist->SetTitle("MCSim and TrkMCSim Momenta (MeV/c)");
  electronMCSimMomHist->SetLineColor(kBlue);
  electronTrkMCSimMomHist->SetLineColor(kRed);
  TLegend* legend = new TLegend(0.45, 0.7, 0.73, 0.88);
  legend->SetTextSize(0.03);
  legend->SetBorderSize(0);   
  legend->SetFillStyle(0);
  legend->AddEntry(electronMCSimMomHist, "MCSim", "l");
  legend->AddEntry(electronTrkMCSimMomHist,"TrkMCSim","l");
  electronMCSimMomHist->Draw("HIST");
  electronTrkMCSimMomHist->Draw("HIST SAME");
  legend->Draw();
  c1->SaveAs("mcsimvtrkmcsimMomHistElectrons.pdf");
  c1->Clear();
}
