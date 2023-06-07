// main92.cc is a part of the PYTHIA event generator.
// Copyright (C) 2020 Torbjorn Sjostrand.
// PYTHIA is licenced under the GNU GPL v2 or later, see COPYING for details.
// Please respect the MCnet Guidelines, see GUIDELINES for details.

// This is a simple test program.
// Modified by Rene Brun and Axel Naumann to put the Pythia::event
// into a TTree.

// Header file to access Pythia 8 program elements.
#include "Pythia8/Pythia.h"

// ROOT, for saving Pythia events as trees in a file.
#include "TTree.h"
#include "TFile.h"

using namespace Pythia8;

int main() {

  // Create Pythia instance and set it up to generate hard QCD processes
  // above pTHat = 20 GeV for pp collisions at 14 TeV.
  Pythia pythia;
  pythia.readString("Beams:eCM = 250.");
  pythia.readString("Beams:idA = -11");
  pythia.readString("Beams:idB =  11");
  pythia.readString("PDF:lepton2gamma = on");
  pythia.readString("Photon:Q2max = 2.0");
  pythia.readString("Photon:Wmin  = 5.0");
  pythia.readString("PhotonCollision:all = on");
  pythia.readString("PhotonParton:all = on");
  pythia.readString("HardQCD:qqbar2gg = on");
  pythia.readString("HardQCD:qqbar2qqbarNew = on");
  pythia.readString("HardQCD:qqbar2ccbar = on");
  pythia.readString("HardQCD:qqbar2bbbar = on");

  pythia.init();

  // Set up the ROOT TFile and TTree.
  TFile *file = TFile::Open("pytree.root","recreate");
  Event *event = &pythia.event;
  Info *info = &pythia.info;
  TTree *T = new TTree("Event","Event Tree");
  T->Branch("event",&event);
  TTree *I = new TTree("Info","Info Tree");
  I->Branch("info",&info);

 // Begin event loop. Generate event; skip if generation aborted.
  for (int iEvent = 0; iEvent < 100000; ++iEvent) {
    if (!pythia.next()) continue;

    // Fill the pythia event into the TTree.
    // Warning: the files will rapidly become large if all events
    // are saved. In some cases it may be convenient to do some
    // processing of events and only save those that appear
    // interesting for future analyses.
    T->Fill();
    I->Fill();

  // End event loop.
  }

  // Statistics on event generation.
  pythia.stat();

  //  Write tree.
  T->Print();
  T->Write();
  I->Print();
  I->Write();
  delete file;

  // Done.
  return 0;
}
