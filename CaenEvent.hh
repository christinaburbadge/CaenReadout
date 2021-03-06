#ifndef CAENEVENT_HH
#define CAENEVENT_HH

#include "TObject.h"

#include "CAENDigitizer.h"

class CaenEvent : public TObject {
public:
	CaenEvent() {}
	CaenEvent(int channel, const CAEN_DGTZ_DPP_PSD_Event_t& event);
	~CaenEvent() {}

	void Read(int channel, const CAEN_DGTZ_DPP_PSD_Event_t& event);
	void Print(Option_t* opt = NULL) const;

	void Channel(int value) { fChannel = value; }
	void TriggerTime(uint32_t value) { fTriggerTime = value; }
	void Energy(uint16_t value) { fEnergy = value; }
	void ExtendedTimestamp(uint16_t value) { fExtendedTimestamp = value; }
	void Cfd(uint16_t value) { fCfd = value; }
	void LostTrigger(bool value) { fLostTrigger = value; }
	void OverRange(bool value) { fOverRange = value; }
	void KiloCount(bool value) { fKiloCount = value; }
	void NLostCount(bool value) { fNLostCount = value; }
	void ShortGate(uint16_t value) { fShortGate = value; }

	int Channel() const { return fChannel; }
	uint32_t TriggerTime() const { return fTriggerTime; }
	uint16_t Energy() const { return fEnergy; }
	uint16_t ExtendedTimestamp() const { return fExtendedTimestamp; }
	uint16_t Cfd() const { return fCfd; }
	bool LostTrigger() const { return fLostTrigger; }
	bool OverRange() const { return fOverRange; }
	bool KiloCount() const { return fKiloCount; }
	bool NLostCount() const { return fNLostCount; }
	uint16_t ShortGate() const { return fShortGate; }

	uint64_t GetTimestamp() const;
	double GetTime() const;

	bool CheckTime() const { return (fExtendedTimestamp != 0 || fTriggerTime != 0 || fCfd != 0); }

private:
	int fChannel;
	uint32_t fTriggerTime;
	uint16_t fEnergy;
	uint16_t fExtendedTimestamp;
	uint16_t fCfd;
	bool fLostTrigger;
	bool fOverRange;
	bool fKiloCount;
	bool fNLostCount;
	uint16_t fShortGate;
	uint32_t fFormat;
	uint32_t fFormat2;
	uint16_t fBaseline;
	uint16_t fPur;

	ClassDef(CaenEvent, 2)
};
#endif
