#ifndef GITSTATUSLIST_H
#define GITSTATUSLIST_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/diff_perfdata.h"
#include "../include/repository.h"
#include "../include/status_options.h"
// Forward declaration.
struct git_status_list {
};

using namespace node;
using namespace v8;

class GitStatusList : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_status_list *GetValue();
    git_status_list **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                

  private:


    GitStatusList(git_status_list *raw, bool selfFreeing);
    ~GitStatusList();
                
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Entrycount);

    static NAN_METHOD(Free);

    struct GetPerfdataBaton {
      int error_code;
      const git_error* error;
      git_diff_perfdata * out;
      const git_status_list * status;
    };
    class GetPerfdataWorker : public Nan::AsyncWorker {
      public:
        GetPerfdataWorker(
            GetPerfdataBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~GetPerfdataWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        GetPerfdataBaton *baton;
    };

    static NAN_METHOD(GetPerfdata);

    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_status_list * out;
      git_repository * repo;
      const git_status_options * opts;
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
    git_status_list *raw;
};

#endif
