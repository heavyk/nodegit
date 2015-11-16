// This is a generated file, modify: generate/templates/struct_content.cc.
#include <nan.h>
#include <string.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32

extern "C" {
  #include <git2.h>
 }

#include <iostream>
#include "../include/functions/copy.h"
#include "../include/stash_apply_options.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/checkout_options.h"
 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitStashApplyOptions::GitStashApplyOptions() {
   git_stash_apply_options wrappedValue = GIT_STASH_APPLY_OPTIONS_INIT;
   this->raw = (git_stash_apply_options*) malloc(sizeof(git_stash_apply_options));
  memcpy(this->raw, &wrappedValue, sizeof(git_stash_apply_options));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitStashApplyOptions::GitStashApplyOptions(git_stash_apply_options* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitStashApplyOptions::~GitStashApplyOptions() {
          if (this->progress_cb != NULL) {
    delete this->progress_cb;
    this->raw->progress_payload = NULL;
  }
         
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitStashApplyOptions::ConstructFields() {
               Local<Object> checkout_optionsTemp = GitCheckoutOptions::New(
            &this->raw->checkout_options,
            false
          )->ToObject();
          this->checkout_options.Reset(checkout_optionsTemp);

   
          // Set the static method call and set the payload for this function to be
          // the current instance
          this->raw->progress_cb = NULL;
          this->raw->progress_payload = (void *)this;
          this->progress_cb = NULL;
   
          Local<Value> progress_payload = Nan::Undefined();
          this->progress_payload.Reset(progress_payload);
    }

void GitStashApplyOptions::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("StashApplyOptions").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("flags").ToLocalChecked(), GetFlags, SetFlags);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("checkoutOptions").ToLocalChecked(), GetCheckoutOptions, SetCheckoutOptions);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("progressCb").ToLocalChecked(), GetProgressCb, SetProgressCb);
     
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("StashApplyOptions").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitStashApplyOptions::JSNewFunction) {
  GitStashApplyOptions* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitStashApplyOptions();
  }
  else {
    instance = new GitStashApplyOptions(static_cast<git_stash_apply_options*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitStashApplyOptions::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitStashApplyOptions::constructor_template), 2, argv).ToLocalChecked());
}

git_stash_apply_options *GitStashApplyOptions::GetValue() {
  return this->raw;
}

git_stash_apply_options **GitStashApplyOptions::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitStashApplyOptions::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitStashApplyOptions::GetVersion) {

      GitStashApplyOptions *wrapper = Nan::ObjectWrap::Unwrap<GitStashApplyOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitStashApplyOptions::SetVersion) {

      GitStashApplyOptions *wrapper = Nan::ObjectWrap::Unwrap<GitStashApplyOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitStashApplyOptions::GetFlags) {

      GitStashApplyOptions *wrapper = Nan::ObjectWrap::Unwrap<GitStashApplyOptions>(info.This());

        info.GetReturnValue().Set(Nan::New((int)wrapper->GetValue()->flags));

     }

    NAN_SETTER(GitStashApplyOptions::SetFlags) {

      GitStashApplyOptions *wrapper = Nan::ObjectWrap::Unwrap<GitStashApplyOptions>(info.This());

        if (value->IsNumber()) {
          wrapper->GetValue()->flags = (git_stash_apply_flags) Nan::To<int32_t>(value).FromJust();
        }

     }

      NAN_GETTER(GitStashApplyOptions::GetCheckoutOptions) {

      GitStashApplyOptions *wrapper = Nan::ObjectWrap::Unwrap<GitStashApplyOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->checkout_options));

     }

    NAN_SETTER(GitStashApplyOptions::SetCheckoutOptions) {

      GitStashApplyOptions *wrapper = Nan::ObjectWrap::Unwrap<GitStashApplyOptions>(info.This());

        Local<Object> checkout_options(value->ToObject());

        wrapper->checkout_options.Reset(checkout_options);

        wrapper->raw->checkout_options = *  Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(checkout_options->ToObject())->GetValue() ;

     }

      NAN_GETTER(GitStashApplyOptions::GetProgressCb) {

      GitStashApplyOptions *wrapper = Nan::ObjectWrap::Unwrap<GitStashApplyOptions>(info.This());

        if (wrapper->progress_cb != NULL) {
          info.GetReturnValue().Set(wrapper->progress_cb->GetFunction());
        } else {
          info.GetReturnValue().SetUndefined();
        }

     }

    NAN_SETTER(GitStashApplyOptions::SetProgressCb) {

      GitStashApplyOptions *wrapper = Nan::ObjectWrap::Unwrap<GitStashApplyOptions>(info.This());

        if (wrapper->progress_cb != NULL) {
          delete wrapper->progress_cb;
        }

        if (value->IsFunction()) {
          if (!wrapper->raw->progress_cb) {
            wrapper->raw->progress_cb = (git_stash_apply_progress_cb)progress_cb_cppCallback;
          }

          wrapper->progress_cb = new Nan::Callback(value.As<Function>());
        }

     }

      int GitStashApplyOptions::progress_cb_cppCallback (
          git_stash_apply_progress_t progress,           void * payload        ) {
        ProgressCbBaton* baton = new ProgressCbBaton();

          baton->progress = progress;
          baton->payload = payload;
 
        baton->result = 0;
        baton->req.data = baton;
        baton->done = false;

        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) progress_cb_async);
        uv_async_send(&baton->req);

        while(!baton->done) {
          sleep_for_ms(1);
        }

  
        return baton->result;
      }

      void GitStashApplyOptions::progress_cb_async(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        ProgressCbBaton* baton = static_cast<ProgressCbBaton*>(req->data);
        GitStashApplyOptions* instance = static_cast<GitStashApplyOptions*>(baton-> payload  );

        if (instance->progress_cb->IsEmpty()) {
            baton->result = 0; // no results acquired
 
          baton->done = true;
          return;
        }

    
        Local<Value> argv[2] = {
                Nan::New((int)baton->progress),
                Nan::New(instance->progress_payload)
          };

        Nan::TryCatch tryCatch;
        Local<v8::Value> result = instance->progress_cb->Call(2, argv);

        if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
          Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

          if (thenProp->IsFunction()) {
            // we can be reasonbly certain that the result is a promise
            Local<Object> promise = result->ToObject();

            baton->promise.Reset(promise);

            uv_close((uv_handle_t*) &baton->req, (uv_close_cb) progress_cb_setupAsyncPromisePolling);
            return;
          }
        }

          if (result.IsEmpty() || result->IsNativeError()) {
            baton->result = -1;
          }
          else if (!result->IsNull() && !result->IsUndefined()) {
             if (result->IsNumber()) {
              baton->result = (int)result->ToNumber()->Value();
            }
            else {
              baton->result = 0;
            }
           }
          else {
            baton->result = 0;
          }
         baton->done = true;
        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      void GitStashApplyOptions::progress_cb_setupAsyncPromisePolling(uv_async_t* req) {
        ProgressCbBaton* baton = static_cast<ProgressCbBaton*>(req->data);
        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) progress_cb_asyncPromisePolling);
        uv_async_send(&baton->req);
      }

      void GitStashApplyOptions::progress_cb_asyncPromisePolling(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        ProgressCbBaton* baton = static_cast<ProgressCbBaton*>(req->data);
        Local<Object> promise = Nan::New<Object>(baton->promise);

        Nan::Callback* isPendingFn = new Nan::Callback(Nan::Get(promise, Nan::New("isPending").ToLocalChecked()).ToLocalChecked().As<Function>());
        Local<Value> argv[1]; // MSBUILD won't assign an array of length 0
        Local<Boolean> isPending = isPendingFn->Call(promise, 0, argv)->ToBoolean();

        if (isPending->Value()) {
          uv_async_send(&baton->req);
          return;
        }

        Nan::Callback* isFulfilledFn = new Nan::Callback(Nan::Get(promise, Nan::New("isFulfilled").ToLocalChecked()).ToLocalChecked().As<Function>());
        Local<Boolean> isFulfilled = isFulfilledFn->Call(promise, 0, argv)->ToBoolean();

        if (isFulfilled->Value()) {
          Nan::Callback* resultFn = new Nan::Callback(Nan::Get(promise, Nan::New("value").ToLocalChecked()).ToLocalChecked().As<Function>());
          Local<v8::Value> result = resultFn->Call(promise, 0, argv);

            if (result.IsEmpty() || result->IsNativeError()) {
              baton->result = -1;
            }
            else if (!result->IsNull() && !result->IsUndefined()) {
               if (result->IsNumber()) {
                baton->result = (int)result->ToNumber()->Value();
              }
              else{
                baton->result = 0;
              }
             }
            else {
              baton->result = 0;
            }
           baton->done = true;
        }
        else {
          // promise was rejected
          GitStashApplyOptions* instance = static_cast<GitStashApplyOptions*>(baton-> payload  );
          Local<v8::Object> parent = instance->handle();
          Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
          Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
          parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

          baton->result = -1;
          baton->done = true;
        }

        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      NAN_GETTER(GitStashApplyOptions::GetProgressPayload) {

      GitStashApplyOptions *wrapper = Nan::ObjectWrap::Unwrap<GitStashApplyOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->progress_payload));

     }

    NAN_SETTER(GitStashApplyOptions::SetProgressPayload) {

      GitStashApplyOptions *wrapper = Nan::ObjectWrap::Unwrap<GitStashApplyOptions>(info.This());

        wrapper->progress_payload.Reset(value);

     }

   
Nan::Persistent<Function> GitStashApplyOptions::constructor_template;
