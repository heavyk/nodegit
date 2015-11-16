#ifndef GITREVWALK_H
#define GITREVWALK_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/oid.h"
#include "../include/repository.h"
// Forward declaration.
struct git_revwalk {
};

using namespace node;
using namespace v8;

class GitRevwalk : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_revwalk *GetValue();
    git_revwalk **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                                        

  private:


    GitRevwalk(git_revwalk *raw, bool selfFreeing);
    ~GitRevwalk();
                                                        
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Hide);

    static NAN_METHOD(HideGlob);

    static NAN_METHOD(HideHead);

    static NAN_METHOD(HideRef);

    static NAN_METHOD(Create);

    struct NextBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_revwalk * walk;
    };
    class NextWorker : public Nan::AsyncWorker {
      public:
        NextWorker(
            NextBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~NextWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        NextBaton *baton;
    };

    static NAN_METHOD(Next);

    static NAN_METHOD(Push);

    static NAN_METHOD(PushGlob);

    static NAN_METHOD(PushHead);

    static NAN_METHOD(PushRange);

    static NAN_METHOD(PushRef);

    static NAN_METHOD(Repository);

    static NAN_METHOD(Reset);

    static NAN_METHOD(SimplifyFirstParent);

    static NAN_METHOD(Sorting);
    git_revwalk *raw;
};

#endif
