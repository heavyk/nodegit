#ifndef GITCRED_H
#define GITCRED_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitCred : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_cred *GetValue();
    git_cred **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                  

  private:


    GitCred(git_cred *raw, bool selfFreeing);
    ~GitCred();
                                  
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(DefaultNew);

    static NAN_METHOD(HasUsername);

    static NAN_METHOD(SshKeyFromAgent);

    struct SshKeyMemoryNewBaton {
      int error_code;
      const git_error* error;
      git_cred * out;
      const char * username;
      const char * publickey;
      const char * privatekey;
      const char * passphrase;
    };
    class SshKeyMemoryNewWorker : public Nan::AsyncWorker {
      public:
        SshKeyMemoryNewWorker(
            SshKeyMemoryNewBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SshKeyMemoryNewWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SshKeyMemoryNewBaton *baton;
    };

    static NAN_METHOD(SshKeyMemoryNew);

    static NAN_METHOD(SshKeyNew);

    struct UsernameNewBaton {
      int error_code;
      const git_error* error;
      git_cred * cred;
      const char * username;
    };
    class UsernameNewWorker : public Nan::AsyncWorker {
      public:
        UsernameNewWorker(
            UsernameNewBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~UsernameNewWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        UsernameNewBaton *baton;
    };

    static NAN_METHOD(UsernameNew);

    static NAN_METHOD(UserpassPlaintextNew);
    git_cred *raw;
};

#endif
