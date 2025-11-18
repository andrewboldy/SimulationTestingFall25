//----------------------------------------------------------------------------------

//TargetIPAMomCompare(const string &TargetHalfFieldFilelist, const string &TargetFullFieldFilelist, const string &IPAHalfFieldFilelist, const string &IPAFullFieldFilelist)
//Written by Andrew Boldy
//University of South Carolina
//Fall 2025

//----------------------------------------------------------------------------------

//Plots the electron momentum for filelists in a histogram to compare the 4 different setups for .
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

void TargetIPAMomCompare(const string &TargetHalfFieldFilelist, const string &TargetFullFieldFilelist, const string &IPAHalfFieldFilelist, const string &IPAFullFieldFilelist)
{
  //Initialization of Variables that will be used 
  TCanvas* c1 = new TCanvas("c1","c1"); //initialize canvas
  TH1F* TargetFullFieldMomHist = new TH1F("TargetFullFieldMomHist","Momentum (MeV/c) for Electrons Originating from the Target in Full Strength DS Field", 50, 10, 115);
  TH1F* TargetHalfFieldMomHist = new TH1F("TargetHalfFieldMomHist", "Momentum (MeV/c) for Electrons Originating from the Target in Half Strength DS Field", 50, 10, 115);
  TH1F* IPAFullFieldMomHist = new TH1F("IPAFullFieldMomHist", "Momentum (MeV/c) for Electrons Originating from the IPA in Full Strength DS Field", 50, 10, 115);
  TH1F* IPAHalfFieldMomHist = new TH1F("IPAHalfFieldMomHist", "Momentum (MeV/c) for Electrons Originating from the IPA in Half Strenght DS Field", 50, 10, 115);
  TLegend* leg = new TLegend(0.1, 0.7, 0.38, 0.88);
  RooUtil targetFullFieldUtil(TargetFullFieldFilelist);
  RooUtil targetHalfFieldUtil(TargetHalfFieldFilelist);
  RooUtil IPAFullFieldUtil(IPAFullFieldFilelist);
  RooUtil IPAHalfFieldUtil(IPAHalfFieldFilelist);

  //Begin reading of the root files
  //Identify number of events 
  int numTargetHalfFieldEvents = targetHalfFieldUtil.GetNEvents();
  int numTargetFullFieldEvents = targetFullFieldUtil.GetNEvents();
  int numIPAHalfFieldEvents = IPAHalfFieldUtil.GetNEvents();
  int numIPAFullFieldEvents = IPAFullFieldUtil.GetNEvents();

  //Running number of files in each list
  //Initialize all Variables needed to run Number of files 
  ifstream listOfFilesA(TargetHalfFieldFilelist);
  string lineA;
  int numTargetHalfFieldFiles = 0;
  ifstream listOfFilesB(TargetFullFieldFilelist);
  string lineB;
  int numTargetFullFieldFiles = 0;
  ifstream listOfFilesC(IPAHalfFieldFilelist);
  string lineC;
  int numIPAHalfFieldFiles = 0;
  ifstream listOfFilesD(IPAFullFieldFilelist);
  string lineD;
  int numIPAFullFieldFiles = 0;

  while (getline(listOfFilesA,lineA))
  {
    if (!lineA.empty())
    {
      numTargetHalfFieldFiles++;
    }
  }
  while (getline(listOfFilesB,lineB))
  {
    if (!lineB.empty())
    {
      numTargetFullFieldFiles++;
    }
  }
  while (getline(listOfFilesC,lineC))
  {
    if (!lineC.empty())
    {
      numIPAHalfFieldFiles++;
    }
  }
  while (getline(listOfFilesD,lineD))
  {
    if (!lineD.empty())
    {
      numIPAFullFieldFiles++;
    }
  }

  //Print the initialization parts out to console:
  cout << "There are " << numTargetHalfFieldFiles << " files storing data for the target electrons in the half field configuration of the DS." << endl;
  cout << "There are " << numTargetHalfFieldEvents << " events for the target electrons in the half field configuration of the DS." << endl;
  cout << " " << endl;
  cout << "There are " << numTargetFullFieldFiles << " files storing data for the target electrons in the full field configuration of the DS." << endl;
  cout << "There are " << numTargetFullFieldEvents << " events for the target electrons in the full field configuration of the DS." << endl;
  cout << " " << endl; 
  cout << "There are " << numIPAHalfFieldFiles << " files storing data for the IPA electrons in the half field configuration of the DS." << endl;
  cout << "There are " << numIPAHalfFieldEvents << " events for the IPA electrons in the half field configuration of the DS." << endl;
  cout << " " << endl;
  cout << "There are " << numIPAFullFieldFiles << " files storing data for the IPA electrons in the full field configuration of the DS." << endl;
  cout << "There are " << numIPAFullFieldEvents << " events for the IPA electrons in the full field configuration of the DS." << endl;

  //Populating the histograms
  cout << "Populating the histograms for the target in half field configuration." << endl;
  for (int i_event = 0; i_event < numTargetHalfFieldEvents; i_event++)
  {
    auto& event = targetHalfFieldUtil.GetEvent(i_event);
    auto e_minus_tracks = event.GetTracks(is_e_minus);
    for (auto& track : e_minus_tracks)
    {
      if (track.trkmcsim != nullptr)
      {
        for (const auto& mctrack : *(track.trkmcsim))
        {
          if (mctrack.pdg == 11)
          {
            TargetHalfFieldMomHist->Fill(mctrack.mom.R());
          }
        }
      }
    }
  }

  cout << "Populating the histogram for the target in full field configuration." << endl;
  for (int j_event = 0; j_event < numTargetFullFieldEvents; j_event++)
  {
    auto& event = targetFullFieldUtil.GetEvent(j_event);
    auto e_minus_tracks = event.GetTracks(is_e_minus);
    for (auto& track : e_minus_tracks)
    {
      if (track.trkmcsim != nullptr)
      {
        for (const auto& mctrack : *(track.trkmcsim))
        {
          if (mctrack.pdg == 11)
          {
            TargetFullFieldMomHist->Fill(mctrack.mom.R());
          }
        }
      }
    }
  }

  cout << "Populating the histogram for the IPA in half field configuration." << endl;
  for (int k_event = 0; k_event < numIPAHalfFieldEvents; k_event++)
  {
    auto& event = IPAHalfFieldUtil.GetEvent(k_event);
    auto e_minus_tracks = event.GetTracks(is_e_minus);
    for (auto& track : e_minus_tracks)
    {
      if (track.trkmcsim != nullptr)
      {
        for (const auto& mctrack : *(track.trkmcsim))
        {
          if (mctrack.pdg == 11)
          {
            IPAHalfFieldMomHist->Fill(mctrack.mom.R());
          }
        }
      }
    }
  }

  cout << "Populating the histogram for the IPA in full field configuration." << endl;
  for (int l_event = 0; l_event < numIPAFullFieldEvents; l_event++)
  {
    auto& event = IPAFullFieldUtil.GetEvent(l_event);
    auto e_minus_tracks = event.GetTracks(is_e_minus);
    for (auto& track : e_minus_tracks)
    {
      if (track.trkmcsim != nullptr)
      {
        for (const auto& mctrack : *(track.trkmcsim))
        {
          if (mctrack.pdg == 11)
          {
            IPAFullFieldMomHist->Fill(mctrack.mom.R());
          }
        }
      }
    }
  }

  //Formatting and creating the histograms as a plot 
  TargetFullFieldMomHist->SetTitle("Momentum (MeV/c) Comparison For Target and IPA Stops at Full and Half Field Strengths for the DS");
  TargetFullFieldMomHist->SetLineColor(kBlue);
  TargetFullFieldMomHist->SetStats(0);
  TargetHalfFieldMomHist->SetLineColor(kRed);
  TargetHalfFieldMomHist->SetStats(0);
  IPAFullFieldMomHist->SetLineColor(kGreen);
  IPAFullFieldMomHist->SetStats(0);
  IPAHalfFieldMomHist->SetLineColor(kBlack);
  IPAHalfFieldMomHist->SetStats(0);
  TargetFullFieldMomHist->Draw("HIST");
  TargetHalfFieldMomHist->Draw("HIST SAME");
  IPAFullFieldMomHist->Draw("HIST SAME");
  IPAHalfFieldMomHist->Draw("HIST SAME");
  leg->AddEntry(TargetFullFieldMomHist, "Target Full Field","l");
  leg->AddEntry(TargetHalfFieldMomHist, "Target Half Field", "l");
  leg->AddEntry(IPAFullFieldMomHist, "IPA Full Field", "l");
  leg->AddEntry(IPAHalfFieldMomHist, "IPA Half Field", "l");
  leg->SetTextSize(0.03);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->Draw();
  c1->SaveAs("Plots/TargetIPAMomCompare.pdf");
  //c1->Clear();
}
