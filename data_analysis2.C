#include "TFile.h"
#include "TList.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"


TPaveText *Text ();


//_______________________________________________________________________________________________________________________________________________________________________
void data_analysis2 ()  {
    
    
    //Get Input
    TFile *inputFile = TFile::Open ("input/InputFile.root");
    TList *inputlist = (TList*) inputFile -> Get ("Input");
    
    
    //Get Input Histograms
    TH2F *hdEdx_vs_momentum_positive = (TH2F*) inputlist -> FindObject ("hdEdx_vs_momentum_positive");
    hdEdx_vs_momentum_positive -> SetStats(false);
    hdEdx_vs_momentum_positive -> GetXaxis() -> SetTitle("#it{p} (GeV/#it{c}) positive");
    hdEdx_vs_momentum_positive -> GetXaxis() -> SetTitleOffset(1.6);
    hdEdx_vs_momentum_positive -> SetTitleSize(0.045,"x");
    hdEdx_vs_momentum_positive -> SetLabelSize(0.045,"x");
    hdEdx_vs_momentum_positive -> GetXaxis() -> CenterTitle();
    hdEdx_vs_momentum_positive -> GetYaxis() -> SetTitle("TPC d#it{E} / d#it{x} (a.u.)");
    hdEdx_vs_momentum_positive -> GetYaxis() -> SetTitleOffset(1.8);
    hdEdx_vs_momentum_positive -> SetTitleSize(0.045,"y");
    hdEdx_vs_momentum_positive -> SetLabelSize(0.045,"y");
    hdEdx_vs_momentum_positive -> GetYaxis() -> CenterTitle();

    TH2F *hdEdx_vs_momentum_negative = (TH2F*) inputlist -> FindObject ("hdEdx_vs_momentum_negative");
    hdEdx_vs_momentum_negative -> SetStats(false);
    hdEdx_vs_momentum_negative -> GetXaxis() -> SetTitle("#it{p} (GeV/#it{c}) negative");
    hdEdx_vs_momentum_negative -> GetXaxis() -> SetTitleOffset(1.6);
    hdEdx_vs_momentum_negative -> SetTitleSize(0.045,"x");
    hdEdx_vs_momentum_negative -> SetLabelSize(0.045,"x");
    hdEdx_vs_momentum_negative -> GetXaxis() -> CenterTitle();
    hdEdx_vs_momentum_negative -> GetYaxis() -> SetTitle("TPC d#it{E} / d#it{x} (a.u.)");
    hdEdx_vs_momentum_negative -> GetYaxis() -> SetTitleOffset(1.8);
    hdEdx_vs_momentum_negative -> SetTitleSize(0.045,"y");
    hdEdx_vs_momentum_negative -> SetLabelSize(0.045,"y");
    hdEdx_vs_momentum_negative -> GetYaxis() -> CenterTitle();

    TH2F *hdEdx_vs_momentum = (TH2F*) inputlist -> FindObject ("hdEdx_vs_momentum");
    hdEdx_vs_momentum -> SetStats(false);
    hdEdx_vs_momentum -> GetXaxis() -> SetTitle("#it{p} (GeV/#it{c})");
    hdEdx_vs_momentum -> GetXaxis() -> SetTitleOffset(1.6);
    hdEdx_vs_momentum -> SetTitleSize(0.045,"x");
    hdEdx_vs_momentum -> SetLabelSize(0.045,"x");
    hdEdx_vs_momentum -> GetXaxis() -> CenterTitle();
    hdEdx_vs_momentum -> GetYaxis() -> SetTitle("TPC d#it{E} / d#it{x} (a.u.)");
    hdEdx_vs_momentum -> GetYaxis() -> SetTitleOffset(1.8);
    hdEdx_vs_momentum -> SetTitleSize(0.045,"y");
    hdEdx_vs_momentum -> SetLabelSize(0.045,"y");
    hdEdx_vs_momentum -> GetYaxis() -> CenterTitle();

    TH2F *hSigma_vs_momentum = (TH2F*) inputlist -> FindObject ("hSigma_vs_momentum");
    hSigma_vs_momentum -> SetStats(false);
    hSigma_vs_momentum -> GetXaxis() -> SetTitle("#it{p} (GeV/#it{c})");
    hSigma_vs_momentum -> GetXaxis() -> SetTitleOffset(1.6);
    hSigma_vs_momentum -> SetTitleSize(0.045,"x");
    hSigma_vs_momentum -> SetLabelSize(0.045,"x");
    hSigma_vs_momentum -> GetXaxis() -> CenterTitle();
    hSigma_vs_momentum -> GetYaxis() -> SetTitle("TPC d#sigma");
    hSigma_vs_momentum -> GetYaxis() -> SetTitleOffset(1.8);
    hSigma_vs_momentum -> SetTitleSize(0.045,"y");
    hSigma_vs_momentum -> SetLabelSize(0.045,"y");
    hSigma_vs_momentum -> GetYaxis() -> CenterTitle();

    /////////////////////////////////////////////////
    //                                             //
    //  Plot everything now                        //
    //                                             //
    /////////////////////////////////////////////////


    
    //Plot dE/dx for positive tracks
    TCanvas *cdEdx_vs_momentum_positive = new TCanvas ("cdEdx_vs_momentum_positive","",900,700);
    cdEdx_vs_momentum_positive -> cd();
    cdEdx_vs_momentum_positive -> SetTickx(1);
    cdEdx_vs_momentum_positive -> SetTicky(1);
    cdEdx_vs_momentum_positive -> SetLeftMargin(0.18);
    cdEdx_vs_momentum_positive -> SetRightMargin(0.1);
    cdEdx_vs_momentum_positive -> SetBottomMargin(0.15);
    cdEdx_vs_momentum_positive -> SetTopMargin(0.1);
    hdEdx_vs_momentum_positive -> Draw("colz");
    Text() -> Draw();

    //Plot dE/dx for negative tracks
    TCanvas *cdEdx_vs_momentum_negative = new TCanvas ("cdEdx_vs_momentum_negative","",900,700);
    cdEdx_vs_momentum_negative -> cd();
    cdEdx_vs_momentum_negative -> SetTickx(1);
    cdEdx_vs_momentum_negative -> SetTicky(1);
    cdEdx_vs_momentum_negative -> SetLeftMargin(0.18);
    cdEdx_vs_momentum_negative -> SetRightMargin(0.1);
    cdEdx_vs_momentum_negative -> SetBottomMargin(0.15);
    cdEdx_vs_momentum_negative -> SetTopMargin(0.1);
    hdEdx_vs_momentum_negative -> Draw("colz");
    Text() -> Draw();

    //Plot dE/dx for all tracks
    TCanvas *cdEdx_vs_momentum = new TCanvas ("cdEdx_vs_momentum","",900,700);
    cdEdx_vs_momentum -> cd();
    cdEdx_vs_momentum -> SetTickx(1);
    cdEdx_vs_momentum -> SetTicky(1);
    cdEdx_vs_momentum -> SetLeftMargin(0.18);
    cdEdx_vs_momentum -> SetRightMargin(0.1);
    cdEdx_vs_momentum -> SetBottomMargin(0.15);
    cdEdx_vs_momentum -> SetTopMargin(0.1);
    hdEdx_vs_momentum -> Draw("colz");
    Text() -> Draw();

    //Plot sigma for all tracks
    TCanvas *cSigma_vs_momentum = new TCanvas ("cSigma_vs_momentum","",900,700);
    cSigma_vs_momentum -> cd();
    cSigma_vs_momentum -> SetTickx(1);
    cSigma_vs_momentum -> SetTicky(1);
    cSigma_vs_momentum -> SetLeftMargin(0.18);
    cSigma_vs_momentum -> SetRightMargin(0.1);
    cSigma_vs_momentum -> SetBottomMargin(0.15);
    cSigma_vs_momentum -> SetTopMargin(0.1);
    hSigma_vs_momentum -> Draw("colz");
    Text() -> Draw();
}
//_______________________________________________________________________________________________________________________________________________________________________
TPaveText *Text ()  {
    
    TPaveText *text = new TPaveText(0.35,0.75,0.7,0.88, "NDC");
    text -> SetTextSize(0.045);
    text -> SetTextFont(42);
    text -> SetTextColor(1);
    text -> SetFillColor(0);
    text -> SetBorderSize(0);
    text -> AddText ("ALICE work in progress");
    text -> AddText ("Pb#font[122]{-}Pb, #sqrt{#it{s}_{NN}} = 5.02 TeV");

    return text;
}
//_______________________________________________________________________________________________________________________________________________________________________




