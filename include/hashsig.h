#ifndef GITHASHSIG_H
#define GITHASHSIG_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
#include <git2/sys/hashsig.h>
}

// Forward declaration.
struct git_hashsig {
};

using namespace node;
using namespace v8;

class GitHashsig : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_hashsig *GetValue();
    git_hashsig **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                   

  private:


    GitHashsig(git_hashsig *raw, bool selfFreeing);
    ~GitHashsig();
                   
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Compare);

    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_hashsig * out;
      const char * buf;
      size_t buflen;
      git_hashsig_option_t opts;
    };
    class CreateWorker : public Nan::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~CreateWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        CreateBaton *baton;
    };

    static NAN_METHOD(Create);

    struct CreateFromfileBaton {
      int error_code;
      const git_error* error;
      git_hashsig * out;
      const char * path;
      git_hashsig_option_t opts;
    };
    class CreateFromfileWorker : public Nan::AsyncWorker {
      public:
        CreateFromfileWorker(
            CreateFromfileBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~CreateFromfileWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        CreateFromfileBaton *baton;
    };

    static NAN_METHOD(CreateFromfile);

    static NAN_METHOD(Free);
    git_hashsig *raw;
};

#endif
