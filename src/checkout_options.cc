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
#include "../include/checkout_options.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/diff_file.h"
  #include "../include/strarray.h"
  #include "../include/tree.h"
  #include "../include/index.h"
 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitCheckoutOptions::GitCheckoutOptions() {
   git_checkout_options wrappedValue = GIT_CHECKOUT_OPTIONS_INIT;
   this->raw = (git_checkout_options*) malloc(sizeof(git_checkout_options));
  memcpy(this->raw, &wrappedValue, sizeof(git_checkout_options));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitCheckoutOptions::GitCheckoutOptions(git_checkout_options* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitCheckoutOptions::~GitCheckoutOptions() {
                       if (this->notify_cb != NULL) {
    delete this->notify_cb;
    this->raw->notify_payload = NULL;
  }
        if (this->progress_cb != NULL) {
    delete this->progress_cb;
    this->raw->progress_payload = NULL;
  }
                             if (this->perfdata_cb != NULL) {
    delete this->perfdata_cb;
    this->raw->perfdata_payload = NULL;
  }
         
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitCheckoutOptions::ConstructFields() {
                     
          // Set the static method call and set the payload for this function to be
          // the current instance
          this->raw->notify_cb = NULL;
          this->raw->notify_payload = (void *)this;
          this->notify_cb = NULL;
   
          Local<Value> notify_payload = Nan::Undefined();
          this->notify_payload.Reset(notify_payload);
   
          // Set the static method call and set the payload for this function to be
          // the current instance
          this->raw->progress_cb = NULL;
          this->raw->progress_payload = (void *)this;
          this->progress_cb = NULL;
   
          Local<Value> progress_payload = Nan::Undefined();
          this->progress_payload.Reset(progress_payload);
             Local<Object> pathsTemp = GitStrarray::New(
            &this->raw->paths,
            false
          )->ToObject();
          this->paths.Reset(pathsTemp);

             Local<Object> baselineTemp = GitTree::New(
            &this->raw->baseline,
            false
          )->ToObject();
          this->baseline.Reset(baselineTemp);

             Local<Object> baseline_indexTemp = GitIndex::New(
            &this->raw->baseline_index,
            false
          )->ToObject();
          this->baseline_index.Reset(baseline_indexTemp);

               
          // Set the static method call and set the payload for this function to be
          // the current instance
          this->raw->perfdata_cb = NULL;
          this->raw->perfdata_payload = (void *)this;
          this->perfdata_cb = NULL;
   
          Local<Value> perfdata_payload = Nan::Undefined();
          this->perfdata_payload.Reset(perfdata_payload);
    }

void GitCheckoutOptions::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("CheckoutOptions").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("checkoutStrategy").ToLocalChecked(), GetCheckoutStrategy, SetCheckoutStrategy);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("disableFilters").ToLocalChecked(), GetDisableFilters, SetDisableFilters);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("dirMode").ToLocalChecked(), GetDirMode, SetDirMode);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("fileMode").ToLocalChecked(), GetFileMode, SetFileMode);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("fileOpenFlags").ToLocalChecked(), GetFileOpenFlags, SetFileOpenFlags);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("notifyFlags").ToLocalChecked(), GetNotifyFlags, SetNotifyFlags);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("notifyCb").ToLocalChecked(), GetNotifyCb, SetNotifyCb);
          Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("progressCb").ToLocalChecked(), GetProgressCb, SetProgressCb);
          Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("paths").ToLocalChecked(), GetPaths, SetPaths);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("baseline").ToLocalChecked(), GetBaseline, SetBaseline);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("baselineIndex").ToLocalChecked(), GetBaselineIndex, SetBaselineIndex);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("targetDirectory").ToLocalChecked(), GetTargetDirectory, SetTargetDirectory);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("ancestorLabel").ToLocalChecked(), GetAncestorLabel, SetAncestorLabel);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("ourLabel").ToLocalChecked(), GetOurLabel, SetOurLabel);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("theirLabel").ToLocalChecked(), GetTheirLabel, SetTheirLabel);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("perfdataCb").ToLocalChecked(), GetPerfdataCb, SetPerfdataCb);
     
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("CheckoutOptions").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitCheckoutOptions::JSNewFunction) {
  GitCheckoutOptions* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitCheckoutOptions();
  }
  else {
    instance = new GitCheckoutOptions(static_cast<git_checkout_options*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitCheckoutOptions::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitCheckoutOptions::constructor_template), 2, argv).ToLocalChecked());
}

git_checkout_options *GitCheckoutOptions::GetValue() {
  return this->raw;
}

git_checkout_options **GitCheckoutOptions::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitCheckoutOptions::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitCheckoutOptions::GetVersion) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitCheckoutOptions::SetVersion) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitCheckoutOptions::GetCheckoutStrategy) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->checkout_strategy));
     }

    NAN_SETTER(GitCheckoutOptions::SetCheckoutStrategy) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->checkout_strategy = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitCheckoutOptions::GetDisableFilters) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->disable_filters));
     }

    NAN_SETTER(GitCheckoutOptions::SetDisableFilters) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->disable_filters = (int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitCheckoutOptions::GetDirMode) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->dir_mode));
     }

    NAN_SETTER(GitCheckoutOptions::SetDirMode) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->dir_mode = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitCheckoutOptions::GetFileMode) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->file_mode));
     }

    NAN_SETTER(GitCheckoutOptions::SetFileMode) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->file_mode = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitCheckoutOptions::GetFileOpenFlags) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->file_open_flags));
     }

    NAN_SETTER(GitCheckoutOptions::SetFileOpenFlags) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->file_open_flags = (int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitCheckoutOptions::GetNotifyFlags) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->notify_flags));
     }

    NAN_SETTER(GitCheckoutOptions::SetNotifyFlags) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->notify_flags = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitCheckoutOptions::GetNotifyCb) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->notify_cb != NULL) {
          info.GetReturnValue().Set(wrapper->notify_cb->GetFunction());
        } else {
          info.GetReturnValue().SetUndefined();
        }

     }

    NAN_SETTER(GitCheckoutOptions::SetNotifyCb) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->notify_cb != NULL) {
          delete wrapper->notify_cb;
        }

        if (value->IsFunction()) {
          if (!wrapper->raw->notify_cb) {
            wrapper->raw->notify_cb = (git_checkout_notify_cb)notify_cb_cppCallback;
          }

          wrapper->notify_cb = new Nan::Callback(value.As<Function>());
        }

     }

      int GitCheckoutOptions::notify_cb_cppCallback (
          git_checkout_notify_t why,           const char * path,           const git_diff_file * baseline,           const git_diff_file * target,           const git_diff_file * workdir,           void * payload        ) {
        NotifyCbBaton* baton = new NotifyCbBaton();

          baton->why = why;
          baton->path = path;
          baton->baseline = baseline;
          baton->target = target;
          baton->workdir = workdir;
          baton->payload = payload;
 
        baton->result = 0;
        baton->req.data = baton;
        baton->done = false;

        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) notify_cb_async);
        uv_async_send(&baton->req);

        while(!baton->done) {
          sleep_for_ms(1);
        }

  
        return baton->result;
      }

      void GitCheckoutOptions::notify_cb_async(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        NotifyCbBaton* baton = static_cast<NotifyCbBaton*>(req->data);
        GitCheckoutOptions* instance = static_cast<GitCheckoutOptions*>(baton->     payload  );

        if (instance->notify_cb->IsEmpty()) {
            baton->result = 1; // no results acquired
 
          baton->done = true;
          return;
        }

            if (baton->path == NULL) {
              baton->path = "";
          }
          
        Local<Value> argv[6] = {
                Nan::New((int)baton->why),
                  Nan::New(baton->path).ToLocalChecked(),
                  GitDiffFile::New((void *)baton->baseline, false),
                  GitDiffFile::New((void *)baton->target, false),
                  GitDiffFile::New((void *)baton->workdir, false),
                Nan::New(instance->notify_payload)
          };

        Nan::TryCatch tryCatch;
        Local<v8::Value> result = instance->notify_cb->Call(6, argv);

        if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
          Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

          if (thenProp->IsFunction()) {
            // we can be reasonbly certain that the result is a promise
            Local<Object> promise = result->ToObject();

            baton->promise.Reset(promise);

            uv_close((uv_handle_t*) &baton->req, (uv_close_cb) notify_cb_setupAsyncPromisePolling);
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
              baton->result = 1;
            }
           }
          else {
            baton->result = 1;
          }
         baton->done = true;
        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      void GitCheckoutOptions::notify_cb_setupAsyncPromisePolling(uv_async_t* req) {
        NotifyCbBaton* baton = static_cast<NotifyCbBaton*>(req->data);
        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) notify_cb_asyncPromisePolling);
        uv_async_send(&baton->req);
      }

      void GitCheckoutOptions::notify_cb_asyncPromisePolling(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        NotifyCbBaton* baton = static_cast<NotifyCbBaton*>(req->data);
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
                baton->result = 1;
              }
             }
            else {
              baton->result = 1;
            }
           baton->done = true;
        }
        else {
          // promise was rejected
          GitCheckoutOptions* instance = static_cast<GitCheckoutOptions*>(baton->     payload  );
          Local<v8::Object> parent = instance->handle();
          Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
          Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
          parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

          baton->result = -1;
          baton->done = true;
        }

        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      NAN_GETTER(GitCheckoutOptions::GetNotifyPayload) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->notify_payload));

     }

    NAN_SETTER(GitCheckoutOptions::SetNotifyPayload) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        wrapper->notify_payload.Reset(value);

     }

      NAN_GETTER(GitCheckoutOptions::GetProgressCb) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->progress_cb != NULL) {
          info.GetReturnValue().Set(wrapper->progress_cb->GetFunction());
        } else {
          info.GetReturnValue().SetUndefined();
        }

     }

    NAN_SETTER(GitCheckoutOptions::SetProgressCb) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->progress_cb != NULL) {
          delete wrapper->progress_cb;
        }

        if (value->IsFunction()) {
          if (!wrapper->raw->progress_cb) {
            wrapper->raw->progress_cb = (git_checkout_progress_cb)progress_cb_cppCallback;
          }

          wrapper->progress_cb = new Nan::Callback(value.As<Function>());
        }

     }

      int GitCheckoutOptions::progress_cb_cppCallback (
          const char * path,           size_t completed_steps,           size_t total_steps,           void * payload        ) {
        ProgressCbBaton* baton = new ProgressCbBaton();

          baton->path = path;
          baton->completed_steps = completed_steps;
          baton->total_steps = total_steps;
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

      void GitCheckoutOptions::progress_cb_async(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        ProgressCbBaton* baton = static_cast<ProgressCbBaton*>(req->data);
        GitCheckoutOptions* instance = static_cast<GitCheckoutOptions*>(baton->   payload  );

        if (instance->progress_cb->IsEmpty()) {
            baton->result = 1; // no results acquired
 
          baton->done = true;
          return;
        }

          if (baton->path == NULL) {
              baton->path = "";
          }
        
        Local<Value> argv[4] = {
                Nan::New(baton->path).ToLocalChecked(),
                  // HACK: NAN should really have an overload for Nan::New to support size_t
                Nan::New((unsigned int)baton->completed_steps),
                  // HACK: NAN should really have an overload for Nan::New to support size_t
                Nan::New((unsigned int)baton->total_steps),
                Nan::New(instance->progress_payload)
          };

        Nan::TryCatch tryCatch;
        Local<v8::Value> result = instance->progress_cb->Call(4, argv);

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
              baton->result = 1;
            }
           }
          else {
            baton->result = 1;
          }
         baton->done = true;
        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      void GitCheckoutOptions::progress_cb_setupAsyncPromisePolling(uv_async_t* req) {
        ProgressCbBaton* baton = static_cast<ProgressCbBaton*>(req->data);
        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) progress_cb_asyncPromisePolling);
        uv_async_send(&baton->req);
      }

      void GitCheckoutOptions::progress_cb_asyncPromisePolling(uv_async_t* req, int status) {
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
                baton->result = 1;
              }
             }
            else {
              baton->result = 1;
            }
           baton->done = true;
        }
        else {
          // promise was rejected
          GitCheckoutOptions* instance = static_cast<GitCheckoutOptions*>(baton->   payload  );
          Local<v8::Object> parent = instance->handle();
          Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
          Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
          parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

          baton->result = -1;
          baton->done = true;
        }

        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      NAN_GETTER(GitCheckoutOptions::GetProgressPayload) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->progress_payload));

     }

    NAN_SETTER(GitCheckoutOptions::SetProgressPayload) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        wrapper->progress_payload.Reset(value);

     }

      NAN_GETTER(GitCheckoutOptions::GetPaths) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->paths));

     }

    NAN_SETTER(GitCheckoutOptions::SetPaths) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        Local<Object> paths(value->ToObject());

        wrapper->paths.Reset(paths);

        wrapper->raw->paths = * StrArrayConverter::Convert(paths->ToObject()) ;

     }

      NAN_GETTER(GitCheckoutOptions::GetBaseline) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->baseline));

     }

    NAN_SETTER(GitCheckoutOptions::SetBaseline) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        Local<Object> baseline(value->ToObject());

        wrapper->baseline.Reset(baseline);

        wrapper->raw->baseline =   Nan::ObjectWrap::Unwrap<GitTree>(baseline->ToObject())->GetValue() ;

     }

      NAN_GETTER(GitCheckoutOptions::GetBaselineIndex) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->baseline_index));

     }

    NAN_SETTER(GitCheckoutOptions::SetBaselineIndex) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        Local<Object> baseline_index(value->ToObject());

        wrapper->baseline_index.Reset(baseline_index);

        wrapper->raw->baseline_index =   Nan::ObjectWrap::Unwrap<GitIndex>(baseline_index->ToObject())->GetValue() ;

     }

      NAN_GETTER(GitCheckoutOptions::GetTargetDirectory) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->GetValue()->target_directory) {
          info.GetReturnValue().Set(Nan::New<String>(wrapper->GetValue()->target_directory).ToLocalChecked());
        }
        else {
          return;
        }

     }

    NAN_SETTER(GitCheckoutOptions::SetTargetDirectory) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->GetValue()->target_directory) {
        }

        String::Utf8Value str(value);
        wrapper->GetValue()->target_directory = strdup(*str);

     }

      NAN_GETTER(GitCheckoutOptions::GetAncestorLabel) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->GetValue()->ancestor_label) {
          info.GetReturnValue().Set(Nan::New<String>(wrapper->GetValue()->ancestor_label).ToLocalChecked());
        }
        else {
          return;
        }

     }

    NAN_SETTER(GitCheckoutOptions::SetAncestorLabel) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->GetValue()->ancestor_label) {
        }

        String::Utf8Value str(value);
        wrapper->GetValue()->ancestor_label = strdup(*str);

     }

      NAN_GETTER(GitCheckoutOptions::GetOurLabel) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->GetValue()->our_label) {
          info.GetReturnValue().Set(Nan::New<String>(wrapper->GetValue()->our_label).ToLocalChecked());
        }
        else {
          return;
        }

     }

    NAN_SETTER(GitCheckoutOptions::SetOurLabel) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->GetValue()->our_label) {
        }

        String::Utf8Value str(value);
        wrapper->GetValue()->our_label = strdup(*str);

     }

      NAN_GETTER(GitCheckoutOptions::GetTheirLabel) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->GetValue()->their_label) {
          info.GetReturnValue().Set(Nan::New<String>(wrapper->GetValue()->their_label).ToLocalChecked());
        }
        else {
          return;
        }

     }

    NAN_SETTER(GitCheckoutOptions::SetTheirLabel) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->GetValue()->their_label) {
        }

        String::Utf8Value str(value);
        wrapper->GetValue()->their_label = strdup(*str);

     }

      NAN_GETTER(GitCheckoutOptions::GetPerfdataCb) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->perfdata_cb != NULL) {
          info.GetReturnValue().Set(wrapper->perfdata_cb->GetFunction());
        } else {
          info.GetReturnValue().SetUndefined();
        }

     }

    NAN_SETTER(GitCheckoutOptions::SetPerfdataCb) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        if (wrapper->perfdata_cb != NULL) {
          delete wrapper->perfdata_cb;
        }

        if (value->IsFunction()) {
          if (!wrapper->raw->perfdata_cb) {
            wrapper->raw->perfdata_cb = (git_checkout_perfdata_cb)perfdata_cb_cppCallback;
          }

          wrapper->perfdata_cb = new Nan::Callback(value.As<Function>());
        }

     }

      int GitCheckoutOptions::perfdata_cb_cppCallback (
          const git_checkout_perfdata * perfdata,           void * payload        ) {
        PerfdataCbBaton* baton = new PerfdataCbBaton();

          baton->perfdata = perfdata;
          baton->payload = payload;
 
        baton->result = 0;
        baton->req.data = baton;
        baton->done = false;

        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) perfdata_cb_async);
        uv_async_send(&baton->req);

        while(!baton->done) {
          sleep_for_ms(1);
        }

  
        return baton->result;
      }

      void GitCheckoutOptions::perfdata_cb_async(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        PerfdataCbBaton* baton = static_cast<PerfdataCbBaton*>(req->data);
        GitCheckoutOptions* instance = static_cast<GitCheckoutOptions*>(baton-> payload  );

        if (instance->perfdata_cb->IsEmpty()) {
            baton->result = 1; // no results acquired
 
          baton->done = true;
          return;
        }

    
        Local<Value> argv[2] = {
                 Nan::New(baton->perfdata),
                Nan::New(instance->perfdata_payload)
          };

        Nan::TryCatch tryCatch;
        Local<v8::Value> result = instance->perfdata_cb->Call(2, argv);

        if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
          Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

          if (thenProp->IsFunction()) {
            // we can be reasonbly certain that the result is a promise
            Local<Object> promise = result->ToObject();

            baton->promise.Reset(promise);

            uv_close((uv_handle_t*) &baton->req, (uv_close_cb) perfdata_cb_setupAsyncPromisePolling);
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
              baton->result = 1;
            }
           }
          else {
            baton->result = 1;
          }
         baton->done = true;
        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      void GitCheckoutOptions::perfdata_cb_setupAsyncPromisePolling(uv_async_t* req) {
        PerfdataCbBaton* baton = static_cast<PerfdataCbBaton*>(req->data);
        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) perfdata_cb_asyncPromisePolling);
        uv_async_send(&baton->req);
      }

      void GitCheckoutOptions::perfdata_cb_asyncPromisePolling(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        PerfdataCbBaton* baton = static_cast<PerfdataCbBaton*>(req->data);
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
                baton->result = 1;
              }
             }
            else {
              baton->result = 1;
            }
           baton->done = true;
        }
        else {
          // promise was rejected
          GitCheckoutOptions* instance = static_cast<GitCheckoutOptions*>(baton-> payload  );
          Local<v8::Object> parent = instance->handle();
          Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
          Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
          parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

          baton->result = -1;
          baton->done = true;
        }

        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      NAN_GETTER(GitCheckoutOptions::GetPerfdataPayload) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->perfdata_payload));

     }

    NAN_SETTER(GitCheckoutOptions::SetPerfdataPayload) {

      GitCheckoutOptions *wrapper = Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(info.This());

        wrapper->perfdata_payload.Reset(value);

     }

   
Nan::Persistent<Function> GitCheckoutOptions::constructor_template;
