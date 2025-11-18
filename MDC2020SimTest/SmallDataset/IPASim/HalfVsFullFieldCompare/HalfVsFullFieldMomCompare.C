//----------------------------------------------------------------------------------

//HalfVsFullFieldMomCompare(const string &HalfFieldFilelist, const string &FullFieldFilelist)
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

void HalfVsFullFieldMomCompare(const string &HalfFieldFilelist, const string &FullFieldFilelist)
{
  //initialize variables and structures
  TCanvas* c1 = new TCanvas("c1","c1");
  TH1F* HalfFieldMomHist = new TH1F("HalfFieldMomHist", "Momentum (MeV/c) of a Sample Dataset at Half DS Solenoid Magnetic Field", 50, 10, 115);
  TH1F* FullFieldMomHist = new TH1F("FullFieldMomHist", "Momentum (MeV/c) of a Sample Dataset at Full DS Solenoid Magnetic Field", 50, 10, 115);
  TLegend* leg = new TLegend(0.1, 0.7, 0.38, 0.88);
  RooUtil halfFieldUtil(HalfFieldFilelist);
  RooUtil fullFieldUtil(FullFieldFilelist);

  //Print out information for each of the filelists
  int numHalfFieldEvents = halfFieldUtil.GetNEvents();
  cout << "There are " << numHalfFieldEvents << " events in the half field condiguration of the DS." << endl;
  ifstream listOfFilesA(HalfFieldFilelist);
  int numHalfFieldFiles = 0;
  string lineA;
  while (getline(listOfFilesA,lineA))
  {
    if (!lineA.empty())
    {
      numHalfFieldFiles++;
    }
  }
  cout << "There are " << numHalfFieldFiles << " files in the half field file list." << endl;

  int numFullFieldEvents = fullFieldUtil.GetNEvents();
  cout << "There are " << numFullFieldEvents << " events in the full field condiguration of the DS." << endl;
  ifstream listOfFilesB(FullFieldFilelist);
  int numFullFieldFiles = 0;
  string lineB;
  while (getline(listOfFilesB,lineB))
  {
    if (!lineB.empty())
    {
      numFullFieldFiles++;
    }
  }
  cout << "There are " << numFullFieldFiles << " files in the full field file list." << endl;
   
  //Create the histograms
  cout << "Creating histograms for half field condiguration." << endl;
  for (int i_event = 0; i_event < numHalfFieldEvents; i_event++)
  {
    auto& event = halfFieldUtil.GetEvent(i_event);
    auto e_minus_tracks = event.GetTracks(is_e_minus);
    for (auto& track : e_minus_tracks)
    {
      if (track.trkmcsim != nullptr)
      {
        for (const auto& mctrack : *(track.trkmcsim))
        {
          if (mctrack.pdg == 11)
          {
            HalfFieldMomHist->Fill(mctrack.mom.R());
          }
        }
      }
    }
  }
  cout << "Creating histograms for full field configuration." << endl;
  for (int j_event = 0; j_event < numFullFieldEvents; j_event++)
  {
    auto& event = fullFieldUtil.GetEvent(j_event);
    auto e_minus_tracks = event.GetTracks(is_e_minus);
    for (auto& track : e_minus_tracks)
    {
      if (track.trkmcsim != nullptr)
      {
        for (const auto& mctrack : *(track.trkmcsim))
        {
          if (mctrack.pdg == 11)
          {
            FullFieldMomHist->Fill(mctrack.mom.R());
          }
        }
      }
    }
  }

  //Write to files for viewing
  cout << "Writing separate histograms to files." << endl;
  HalfFieldMomHist->Draw("HIST");
  c1->SaveAs("Plots/HalfFieldMomHist.pdf");
  c1->Clear();
  FullFieldMomHist->Draw("HIST");
  c1->SaveAs("Plots/FullFieldMomHist.pdf");
  c1->Clear();
  cout << "Writing the combined histogram to a file." << endl;
  FullFieldMomHist->SetTitle("Half Field vs. Full Field Momentum (MeV/c)");
  FullFieldMomHist->SetLineColor(kBlue);
  HalfFieldMomHist->SetLineColor(kRed);
  FullFieldMomHist->SetStats(0);
  HalfFieldMomHist->SetStats(0);
  FullFieldMomHist->Draw("HIST");
  HalfFieldMomHist->Draw("HIST SAME");
  leg->AddEntry(HalfFieldMomHist, "Half Field", "l");
  leg->AddEntry(FullFieldMomHist, "Full Field", "l");
  leg->SetTextSize(0.03);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->Draw();
  c1->SaveAs("Plots/HalfVsFullFieldMomCompare.pdf");
}
