#include <iostream>
#include <pocketsphinx.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

#define batdriver 21
#define breadpass 18
#define breaddriver 12
#define batpass 26

ps_decoder_t* ps = nullptr;
cmd_ln_t* config = nullptr;

// Function to listen for commands
void listen_for_commands() {
    // Set up audio device and file
    string device = "plughw:2,0";
    string filename = "audio.wav";
    int duration = 2;
    string command = "arecord -D " + device + " -f cd -c 1 -t wav -d " + to_string(duration) + " -r 16000 " + filename;
    bool running = true;

    while (running) {
        //doing a little dance to tell when to speak
        for (int i = 0; i < 1; i++) {
                softPwmWrite(batdriver, 10);
                softPwmWrite(breaddriver, 10);
                softPwmWrite(breadpass, 21);
                softPwmWrite(batpass, 21);
                this_thread::sleep_for(chrono::milliseconds(1000));
        }
        for (int i = 0; i < 1; i++) {
                softPwmWrite(batdriver, 21);
                softPwmWrite(breaddriver, 21);
                softPwmWrite(breadpass, 10);
                softPwmWrite(batpass, 10);
                this_thread::sleep_for(chrono::milliseconds(1000));
            }
        softPwmWrite(batdriver, 0);
        softPwmWrite(breaddriver, 0);
        softPwmWrite(breadpass, 0);
        softPwmWrite(batpass, 0);
       
        // Record audio for duration
        system(command.c_str());
        cout << "Recording Finished!" << endl;

        // Decode audio file
        FILE* fh = fopen(filename.c_str(), "rb");
        if (fh == nullptr) {
            cerr << "Failed to open audio file." << endl;
            continue;
        }

        ps_start_utt(ps);
        int16_t buf[512];
        size_t nsamp;
        while ((nsamp = fread(buf, 2, 512, fh)) > 0) {
            ps_process_raw(ps, buf, nsamp, FALSE, FALSE);
        }
        ps_end_utt(ps);
        fclose(fh);

        // Get the decoded hypothesis
        char const* hyp = ps_get_hyp(ps, nullptr);
        cout << "Command: " << hyp << endl;

        // Control the motor based on command
        if (string(hyp).find("forward") != string::npos) {
            cout << "Moving forward..." << endl;
            for (int i = 0; i < 1; i++) {
                softPwmWrite(batdriver, 10);
                softPwmWrite(breaddriver, 10);
                softPwmWrite(breadpass, 21);
                softPwmWrite(batpass, 21);
                this_thread::sleep_for(chrono::milliseconds(5000));
            }
        }
        else if (string(hyp).find("back") != string::npos) {
            cout << "Moving backward..." << endl;
            for (int i = 0; i < 1; i++) {
                softPwmWrite(batdriver, 21);
                softPwmWrite(breaddriver, 21);
                softPwmWrite(breadpass, 10);
                softPwmWrite(batpass, 10);
                this_thread::sleep_for(chrono::milliseconds(5000));
            }
        }
        else if (string(hyp).find("left") != string::npos) {
            cout << "Turning left..." << endl;
            for (int i = 0; i < 1; i++) {
                softPwmWrite(batdriver, 10);
                softPwmWrite(breaddriver, 10);
                softPwmWrite(breadpass, 10);
                softPwmWrite(batpass, 10);
                this_thread::sleep_for(chrono::milliseconds(2500));
            }
        }
        else if (string(hyp).find("right") != string::npos) {
            cout << "Turning right..." << endl;
            for (int i = 0; i < 1; i++) {
                softPwmWrite(batdriver, 21);
                softPwmWrite(breaddriver, 21);
                softPwmWrite(breadpass, 21);
                softPwmWrite(batpass, 21);
                this_thread::sleep_for(chrono::milliseconds(2500));
            }
        }
        else if (string(hyp).find("donuts") != string::npos) {
            cout << "doing donuts!!!" << endl;
            for (int i = 0; i < 1; i++) {
                softPwmWrite(batdriver, 21);
                softPwmWrite(breaddriver, 21);
                softPwmWrite(breadpass, 21);
                softPwmWrite(batpass, 21);
                this_thread::sleep_for(chrono::milliseconds(10000));
            }
        }
        else if (string(hyp).find("stop") != string::npos) {
            cout << "Stopping..." << endl;
            running = false;
            system("sudo shutdown -h now");
        }
    }
}

int main() {
    // Initialize wiringPi and motor
    if (wiringPiSetupGpio() < 0) return 1;

    pinMode(batdriver, OUTPUT);
    digitalWrite(batdriver, LOW);
   
pinMode(breadpass, OUTPUT);
digitalWrite(breadpass, LOW);

pinMode(breaddriver, OUTPUT);
digitalWrite(breaddriver, LOW);

pinMode(batpass, OUTPUT);
digitalWrite(batpass, LOW);

softPwmCreate(batdriver, 0, 100);
softPwmCreate(breadpass, 0, 100);
softPwmCreate(breaddriver, 0, 100);
softPwmCreate(batpass, 0, 100);

// Initialize pocketsphinx decoder
config = cmd_ln_init(nullptr, ps_args(), TRUE,
        "-hmm", "/usr/share/pocketsphinx/model/en-us/en-us",
        "-lm", "/usr/share/pocketsphinx/model/en-us/en-us.lm.bin",
        "-dict", "/usr/share/pocketsphinx/model/en-us/cmudict-en-us.dict",
    nullptr);
if (config == nullptr) {
    cerr << "Failed to initialize pocketsphinx." << endl;
    return 1;
}
ps = ps_init(config);
if (ps == nullptr) {
    cerr << "Failed to initialize pocketsphinx." << endl;
    return 1;
}

// Listen for commands
listen_for_commands();

// Clean up
ps_free(ps);
cmd_ln_free_r(config);
return 0;
}