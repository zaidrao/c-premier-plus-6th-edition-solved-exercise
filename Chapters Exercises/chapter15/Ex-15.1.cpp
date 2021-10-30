// tv.h -- Tv and Remote classes
#ifndef TV_H_
#define TV_H_

class Remote;
class Tv
{
  public:
    friend class Remote; // Remote can access Tv private parts
    enum
    {
        Off,
        On
    };
    enum
    {
        MinVal,
        MaxVal = 20
    };
    enum
    {
        Antenna,
        Cable
    };
    enum
    {
        TV,
        DVD
    };
    Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() { state = (state == On) ? Off : On; }
    bool ison() const { return state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
    void set_input() { input = (input == TV) ? DVD : TV; }
    void set_R_state(Remote &r);
    void settings() const; // display all settings
  private:
    int state;      // on or off
    int volume;     // assumed to be digitized
    int maxchannel; // maximum number of channels
    int channel;    // current channel setting
    int mode;       // broadcast or cable
    int input;      // TV or DVD
};
class Remote
{
  private:
    friend class Tv;
    int mode; // controls TV or DVD
    int state; // state interactive or normal
  public:
    enum
    {
        normal,
        interactive
    };
    void setState(Tv & t);
    Remote(int m = Tv::TV, int s= normal) : mode(m), state(s) {}
    bool volup(Tv &t) { return t.volup(); }
    bool voldown(Tv &t) { return t.voldown(); }
    void onoff(Tv &t) { t.onoff(); }
    void chanup(Tv &t) { t.chanup(); }
    void chandown(Tv &t) { t.chandown(); }
    void set_chan(Tv &t, int c) { t.channel = c; }
    void State()const;
    void set_mode(Tv &t) { t.set_mode(); }
    void set_input(Tv &t) { t.set_input(); }
};
#endif

#include <iostream>

int main()
{
    using std::cout;
    Tv s42;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.settings();
    Remote grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    grey.State();
    cout << "\n42\" settings after using remote:\n";
    s42.settings();
    Tv s58(Tv::On);
    s58.set_mode();
    s58.set_R_state(grey);
    grey.State();
    grey.set_chan(s58,28);
    cout << "\n58\" settings:\n";
    s58.settings();
    return 0;
}
// tvR.cpp -- methods for the Tv class

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}
void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}
void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}
void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off ? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
    }
}
void Tv::set_R_state(Remote &r)
{
     r.setState(*this);
}

// tvR.cpp -- methods for the Remote class

void Remote::State()const
{
    std::cout << "Remote mode is " << (state == normal ? "Normal" : "Interactive");
}

void Remote::setState(Tv &t)
{
    if(t.ison())
    state = (state == normal) ? interactive : normal;
}