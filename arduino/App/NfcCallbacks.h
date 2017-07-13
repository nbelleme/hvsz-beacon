class NfcCallbacks {
public:
  NfcCallbacks();
  virtual void onCardIn() = 0;
  virtual void onCardHold() = 0;
  virtual void onCardOut() = 0;
};
