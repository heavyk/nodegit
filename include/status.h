#ifndef GITSTATUS_H
#define GITSTATUS_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
#include <git2/sys/diff.h>
}

#include "../include/status_list.h"
#include "../include/status_entry.h"
#include "../include/repository.h"
#include "../include/status_options.h"

using namespace node;
using namespace v8;

class GitStatus : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

              static int Foreach_callback_cppCallback (
      const char * path
      ,
       unsigned int status_flags
      ,
       void * payload
      );

    static void Foreach_callback_async(uv_async_t* req, int status);
    static void Foreach_callback_setupAsyncPromisePolling(uv_async_t* req);
    static void Foreach_callback_asyncPromisePolling(uv_async_t* req, int status);
    struct Foreach_CallbackBaton {
      const char * path;
      unsigned int status_flags;
      void * payload;
 
      uv_async_t req;
      int result;
      Nan::Persistent<Object> promise;
      bool done;
    };
          static int ForeachExt_callback_cppCallback (
      const char * path
      ,
       unsigned int status_flags
      ,
       void * payload
      );

    static void ForeachExt_callback_async(uv_async_t* req, int status);
    static void ForeachExt_callback_setupAsyncPromisePolling(uv_async_t* req);
    static void ForeachExt_callback_asyncPromisePolling(uv_async_t* req, int status);
    struct ForeachExt_CallbackBaton {
      const char * path;
      unsigned int status_flags;
      void * payload;
 
      uv_async_t req;
      int result;
      Nan::Persistent<Object> promise;
      bool done;
    };
          

  private:


                          
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Byindex);

    static NAN_METHOD(File);

    struct ForeachBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_status_cb callback;
      void * payload;
    };
    class ForeachWorker : public Nan::AsyncWorker {
      public:
        ForeachWorker(
            ForeachBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ForeachWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ForeachBaton *baton;
    };

    static NAN_METHOD(Foreach);

    struct ForeachExtBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const git_status_options * opts;
      git_status_cb callback;
      void * payload;
    };
    class ForeachExtWorker : public Nan::AsyncWorker {
      public:
        ForeachExtWorker(
            ForeachExtBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ForeachExtWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ForeachExtBaton *baton;
    };

    static NAN_METHOD(ForeachExt);

    static NAN_METHOD(ShouldIgnore);

    struct Foreach_globalPayload {
      Nan::Callback * callback;

      Foreach_globalPayload() {
        callback = NULL;
      }

      ~Foreach_globalPayload() {
        if (callback != NULL) {
          delete callback;
        }
      }
    };

    struct ForeachExt_globalPayload {
      Nan::Callback * callback;

      ForeachExt_globalPayload() {
        callback = NULL;
      }

      ~ForeachExt_globalPayload() {
        if (callback != NULL) {
          delete callback;
        }
      }
    };
};

#endif
