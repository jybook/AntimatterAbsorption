#ifndef AnalysisTask0_cxx
#define AnalysisTask0_cxx

//==================================== ANALYSIS TASK ====================================//
//                                                                                       //
//   The first analysis task - TPC response (sigma vs momentum)                          //                                               //
//                                                                                       //
//=======================================================================================//

#include "AliAnalysisTaskSE.h"
#include "AliAnalysisUtils.h"
#include "AliAnalysisTask.h"
#include "AliPIDResponse.h"
#include "AliEventplane.h"
#include "AliAODVertex.h"
#include "AliEventCuts.h"
#include "AliAODEvent.h"
#include "AliAODTrack.h"
#include "TList.h"
#include "TH1F.h"
#include "TH2F.h"

class AnalysisTask0 : public AliAnalysisTaskSE {
    
public:
    AnalysisTask0();
    AnalysisTask0(const char *name);
    virtual ~AnalysisTask0();
    
    
    //Analysis Cuts
    void SetAnalysisCuts (
                           Double_t CentralityMin,
                           Double_t CentralityMax,
                           Double_t VertexZmin,
                           Double_t VertexZmax,
                           Int_t    NumberOfVertexContributorsMin,
                           Double_t MagFieldSign,
                           Double_t DCAxyMax,
                           Double_t DCAzMax,
                           Double_t PtMin,
                           Double_t PtMax,
                           Double_t EtaMax,
                           Int_t    NumberOfClustersITSMin,
                           Int_t    NumberOfClustersTPCMin,
                           Int_t    NumberOfClustersTRDMin,
                           Int_t    NumberOfClustersTPCdEdxMin,
                           Int_t    NumberOfCrossedRowsMin,
                           Double_t CrossedRowsOverFindableClsMin,
                           Double_t ChiSquarePerNDFMax,
                           Double_t ChiSquareTRDMax,
                           Int_t    NumberOfTRDtrackletsPIDMin,
                           Bool_t   IsTRDrefit,
                           Double_t TPCnsigmaDeuteronMax,
                           Double_t TOFnsigmaDeuteronMax
                          )  {
        
        fCentralityMin = CentralityMin;
        fCentralityMax = CentralityMax;
        fVertexZmin = VertexZmin;
        fVertexZmax = VertexZmax;
        fNumberOfVertexContributorsMin = NumberOfVertexContributorsMin;
        fMagFieldSign = MagFieldSign;
        fDCAxyMax = DCAxyMax;
        fDCAzMax = DCAzMax;
        fPtMin = PtMin;
        fPtMax = PtMax;
        fEtaMax = EtaMax;
        fNumberOfClustersITSMin = NumberOfClustersITSMin;
        fNumberOfClustersTPCMin = NumberOfClustersTPCMin;
        fNumberOfClustersTRDMin = NumberOfClustersTRDMin;
        fNumberOfClustersTPCdEdxMin = NumberOfClustersTPCdEdxMin;
        fNumberOfCrossedRowsMin = NumberOfCrossedRowsMin;
        fCrossedRowsOverFindableClsMin = CrossedRowsOverFindableClsMin;
        fChiSquarePerNDFMax = ChiSquarePerNDFMax;
        fChiSquareTRDMax = ChiSquareTRDMax;
        fNumberOfTRDtrackletsPIDMin = NumberOfTRDtrackletsPIDMin;
        fIsTRDrefit = IsTRDrefit;
        fTPCnsigmaDeuteronMax = TPCnsigmaDeuteronMax;
        fTOFnsigmaDeuteronMax = TOFnsigmaDeuteronMax;
    }

    virtual void   UserCreateOutputObjects();
    virtual void   UserExec (Option_t *option);
    
    Bool_t   GetEvent ();
    Bool_t   IsGoodQualityTrack  (AliAODTrack *track);
    Double_t GetDCAxy            (AliAODTrack *track);
    Double_t GetDCAz             (AliAODTrack *track);
    Bool_t   IsDeuteronCandidate (AliAODTrack *track);

    virtual void   Terminate(Option_t *);
    
private:
    AliAODEvent      *fAODevent;//!
    AliPIDResponse   *fPIDResponse;//!
    AliEventCuts      fAODeventCuts;//
    AliAnalysisUtils *fUtils;//!
    TList            *fOutputList;//!
    TList            *fQAList;//!

    Double_t fCentralityMin;//
    Double_t fCentralityMax;//
    Double_t fVertexZmin;//
    Double_t fVertexZmax;//
    Int_t    fNumberOfVertexContributorsMin;//
    Double_t fMagFieldSign;//
    Double_t fDCAxyMax;//
    Double_t fDCAzMax;//
    Double_t fPtMin;//
    Double_t fPtMax;//
    Double_t fEtaMax;//
    Int_t    fNumberOfClustersITSMin;//
    Int_t    fNumberOfClustersTPCMin;//
    Int_t    fNumberOfClustersTRDMin;//
    Int_t    fNumberOfClustersTPCdEdxMin;//
    Int_t    fNumberOfCrossedRowsMin;//
    Double_t fCrossedRowsOverFindableClsMin;//
    Double_t fChiSquarePerNDFMax;//
    Double_t fChiSquareTRDMax;//
    Int_t    fNumberOfTRDtrackletsPIDMin;//
    Bool_t   fIsTRDrefit;//
    Double_t fTPCnsigmaDeuteronMax;//
    Double_t fTOFnsigmaDeuteronMax;//
    
    
    //Histograms
    TH1F *hEvents;//!
 
    TH2F *hdEdx_vs_momentum_positive;//!
    TH2F *hdEdx_vs_momentum_negative;//!
    TH2F *hdEdx_vs_momentum;//!

    TH2F *nSigma_vs_momentum;//!
    
    AnalysisTask0(const AnalysisTask0&);
    AnalysisTask0& operator=(const AnalysisTask0&);
    
    ClassDef(AnalysisTask0, 1);
};
#endif
