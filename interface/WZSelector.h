#ifndef WZSelector_h
#define WZSelector_h

#include <vector>
#include "Analysis/WZAnalysis/interface/ScaleFactor.h"
#include "Analysis/WZAnalysis/interface/WZSelectorBase.h"

class WZSelector : public WZSelectorBase {
public :
    ScaleFactor* pileupSF_;
    ScaleFactor* eIdSF_;
    ScaleFactor* mIdSF_;
    ScaleFactor* mIsoSF_;
    
    std::map<std::string, TH1D*> hists1D_ = {
        { "nTruePU",  {} },
        { "nvtx",  {} },
        { "ZMass",  {} },
        { "ZPt",  {} },
        { "Zlep1_Eta",  {} },
        { "Zlep1_Pt",  {} },
        { "Zlep2_Eta",  {} },
        { "Zlep2_Pt",  {} },
        { "Wlep_Eta",  {} },
        { "Wlep_Pt",  {} },
        { "MET", {} },
        { "MTWZ", {} },
        { "Mass", {} },
        { "Pt", {} },
        { "nJets", {} },
        { "nJetCSVv2T", {} },
        { "jetPt[0]", {} },
        { "jetPt[1]", {} },
        { "jetPt[2]", {} },
        { "jetEta12", {} },
        { "jetEta[0]", {} },
        { "jetEta[1]", {} },
        { "jetEta[2]", {} },
        { "mjj",  {} },
        { "mjj_jesUp",  {} },
        { "mjj_jesDown",  {} },
        { "mjj_jerUp",  {} },
        { "mjj_jerDown",  {} },
        { "MtW",  {} },
        { "dEtajj",  {} },
        { "zep3l",  {} },
        { "zepj3",  {} },
        { "mjj_dEtajj2", {} },
        { "mjj_dEtajj2p25",{} },
        { "mjj_dEtajj2p5",{} },
        { "mjj_dEtajj2p75",{} },
        { "mjj_dEtajj3",{} },
        { "mjj_dEtajj3p25",{} },
        { "mjj_dEtajj3p5",{} },
        { "mjj_dEtajj3p75",{} },
        { "mjj_dEtajj4",{} },
        { "dEtajj_mjj400",{} },
        { "dEtajj_mjj450",{} },
        { "dEtajj_mjj500",{} },
        { "dEtajj_mjj550",{} },
        { "dEtajj_mjj600", {} }
    };
    std::map<std::string, TH2D*> weighthists_ = {
        { "nTruePU",  {} },
        { "nvtx",  {} },
        { "ZMass",  {} },
        { "ZPt",  {} },
        { "Zlep1_Eta",  {} },
        { "Zlep1_Pt",  {} },
        { "Zlep2_Eta",  {} },
        { "Zlep2_Pt",  {} },
        { "Wlep_Eta",  {} },
        { "Wlep_Pt",  {} },
        { "Mass", {} },
        { "Pt", {} },
        { "mjj",  {} },
        { "MtW",  {} },
        { "dEtajj",  {} }
    };

    std::vector<float>* scaleWeights = NULL;
    std::vector<float>* pdfWeights = NULL;
    std::vector<float> lheWeights;
    unsigned int weight_info_;
    float dEtajj;
    float dEtajj_jesUp;
    float dEtajj_jesDown;
    float dEtajj_jerUp;
    float dEtajj_jerDown;
    std::vector<float>* jetPt = NULL;
    std::vector<float>* jetEta = NULL;
    std::vector<float>* jetEta_jesUp = NULL;
    std::vector<float>* jetEta_jesDown = NULL;
    std::vector<float>* jetEta_jerUp = NULL;
    std::vector<float>* jetEta_jerDown = NULL;
    Float_t type1_pfMETEt;
    Float_t nTruePU;
    UInt_t nvtx;
    UInt_t nJets;
    UInt_t nJetCSVv2T;
    Float_t Mass;
    Float_t Eta;
    Float_t ZMass;
    Float_t Pt;
    Float_t ZPt;
    Float_t mjj;
    Float_t mjj_jesUp;
    Float_t mjj_jesDown;
    Float_t mjj_jerUp;
    Float_t mjj_jerDown;
    Float_t l1Eta;
    Float_t l1Pt;
    Float_t l2Eta;
    Float_t l2Pt;
    Float_t l3Eta;
    Float_t l3Pt;
    Float_t l3MtToMET;
    Float_t MtToMET;
    
    TBranch* b_l3MtToMET;
    TBranch* b_MtToMET;
    TBranch* b_pdfWeights;
    TBranch* b_scaleWeights;
    TBranch* b_nJets;
    TBranch* b_nJetCSVv2T;
    TBranch* b_jetPt;
    TBranch* b_jetEta;
    TBranch* b_jetEta_jesUp;
    TBranch* b_jetEta_jesDown;
    TBranch* b_jetEta_jerUp;
    TBranch* b_jetEta_jerDown;
    TBranch* b_nTruePU;
    TBranch* b_nvtx;
    TBranch* b_Mass;
    TBranch* b_Eta;
    TBranch* b_Pt;
    TBranch* b_type1_pfMETEt;
    TBranch* b_ZMass;
    TBranch* b_ZPt;
    TBranch* b_mjj;
    TBranch* b_mjj_jesUp;
    TBranch* b_mjj_jesDown;
    TBranch* b_mjj_jerUp;
    TBranch* b_mjj_jerDown;
    TBranch* b_l1Eta;
    TBranch* b_l1Pt;
    TBranch* b_l2Eta;
    TBranch* b_l2Pt;
    TBranch* b_l3Eta;
    TBranch* b_l3Pt;

    // Readers to access the data (delete the ones you do not need).
    WZSelector(TTree * /*tree*/ =0) { }
    virtual ~WZSelector() { }
    virtual void    Init(TTree *tree) override;
    virtual Bool_t  Process(Long64_t entry) override;
    virtual void    SetupNewDirectory() override;
    virtual void    SlaveBegin(TTree *tree) override;

    ClassDefOverride(WZSelector,0);
protected:
    void LoadBranches(Long64_t entry);
    void FillHistograms(Long64_t entry, float weight, bool noBlind);
    void FillVBSHistograms(Long64_t entry, float weight, bool noBlind);
    bool PassesSelection(bool tightLeps, Selection selection);
    bool PassesVBSSelection(bool noBlind, float dijetMass, float deltaEtajj);
    unsigned int GetLheWeightInfo();
    std::vector<std::string> ReadHistData(std::string histDataString);
};

#endif
