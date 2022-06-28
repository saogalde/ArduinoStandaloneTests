class NTC_3950_10k {
  public:
    NTC_3950_10k(int);
    float readTemperature();
  private:
    int pin;
    float raw2celsius(unsigned int x);
};
