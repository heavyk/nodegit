#ifndef GITSTASH_H
#define GITSTASH_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/repository.h"
#include "../include/stash_apply_options.h"
#include "../include/oid.h"
#include "../include/signature.h"

using namespace node;
using namespace v8;

class GitStash : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

                  static int Foreach_callback_cppCallback (
      size_t index
      ,
       const char * message
      ,
       const git_oid * stash_id
      ,
       void * payload
      );

    static void Foreach_callback_async(uv_async_t* req, int status);
    static void Foreach_callback_setupAsyncPromisePolling(uv_async_t* req);
    static void Foreach_callback_asyncPromisePolling(uv_async_t* req, int status);
    struct Foreach_CallbackBaton {
      size_t index;
      const char * message;
      const git_oid * stash_id;
      void * payload;
 
      uv_async_t req;
      int result;
      Nan::Persistent<Object> promise;
      bool done;
    };
                 

  private:


                               
    static NAN_METHOD(JSNewFunction);


    struct ApplyBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      size_t index;
      const git_stash_apply_options * options;
    };
    class ApplyWorker : public Nan::AsyncWorker {
      public:
        ApplyWorker(
            ApplyBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ApplyWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ApplyBaton *baton;
    };

    static NAN_METHOD(Apply);

    static NAN_METHOD(ApplyInitOptions);

    struct DropBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      size_t index;
    };
    class DropWorker : public Nan::AsyncWorker {
      public:
        DropWorker(
            DropBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~DropWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        DropBaton *baton;
    };

    static NAN_METHOD(Drop);

    struct ForeachBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_stash_cb callback;
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

    struct PopBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      size_t index;
      const git_stash_apply_options * options;
    };
    class PopWorker : public Nan::AsyncWorker {
      public:
        PopWorker(
            PopBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~PopWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        PopBaton *baton;
    };

    static NAN_METHOD(Pop);

    struct SaveBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_repository * repo;
      const git_signature * stasher;
      const char * message;
      unsigned int flags;
    };
    class SaveWorker : public Nan::AsyncWorker {
      public:
        SaveWorker(
            SaveBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SaveWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SaveBaton *baton;
    };

    static NAN_METHOD(Save);

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
};

#endif
