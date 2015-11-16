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
#include "../include/diff_find_options.h"
#include "../include/functions/sleep_for_ms.h"

 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitDiffFindOptions::GitDiffFindOptions() {
   git_diff_find_options wrappedValue = GIT_DIFF_FIND_OPTIONS_INIT;
   this->raw = (git_diff_find_options*) malloc(sizeof(git_diff_find_options));
  memcpy(this->raw, &wrappedValue, sizeof(git_diff_find_options));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitDiffFindOptions::GitDiffFindOptions(git_diff_find_options* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitDiffFindOptions::~GitDiffFindOptions() {
                        
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitDiffFindOptions::ConstructFields() {
                      }

void GitDiffFindOptions::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("DiffFindOptions").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("flags").ToLocalChecked(), GetFlags, SetFlags);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("renameThreshold").ToLocalChecked(), GetRenameThreshold, SetRenameThreshold);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("renameFromRewriteThreshold").ToLocalChecked(), GetRenameFromRewriteThreshold, SetRenameFromRewriteThreshold);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("copyThreshold").ToLocalChecked(), GetCopyThreshold, SetCopyThreshold);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("breakRewriteThreshold").ToLocalChecked(), GetBreakRewriteThreshold, SetBreakRewriteThreshold);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("renameLimit").ToLocalChecked(), GetRenameLimit, SetRenameLimit);
   
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("DiffFindOptions").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitDiffFindOptions::JSNewFunction) {
  GitDiffFindOptions* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitDiffFindOptions();
  }
  else {
    instance = new GitDiffFindOptions(static_cast<git_diff_find_options*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitDiffFindOptions::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitDiffFindOptions::constructor_template), 2, argv).ToLocalChecked());
}

git_diff_find_options *GitDiffFindOptions::GetValue() {
  return this->raw;
}

git_diff_find_options **GitDiffFindOptions::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitDiffFindOptions::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitDiffFindOptions::GetVersion) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitDiffFindOptions::SetVersion) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitDiffFindOptions::GetFlags) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->flags));
     }

    NAN_SETTER(GitDiffFindOptions::SetFlags) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->flags = (uint32_t) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitDiffFindOptions::GetRenameThreshold) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->rename_threshold));
     }

    NAN_SETTER(GitDiffFindOptions::SetRenameThreshold) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->rename_threshold = (uint16_t) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitDiffFindOptions::GetRenameFromRewriteThreshold) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->rename_from_rewrite_threshold));
     }

    NAN_SETTER(GitDiffFindOptions::SetRenameFromRewriteThreshold) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->rename_from_rewrite_threshold = (uint16_t) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitDiffFindOptions::GetCopyThreshold) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->copy_threshold));
     }

    NAN_SETTER(GitDiffFindOptions::SetCopyThreshold) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->copy_threshold = (uint16_t) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitDiffFindOptions::GetBreakRewriteThreshold) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->break_rewrite_threshold));
     }

    NAN_SETTER(GitDiffFindOptions::SetBreakRewriteThreshold) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->break_rewrite_threshold = (uint16_t) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitDiffFindOptions::GetRenameLimit) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->rename_limit));
     }

    NAN_SETTER(GitDiffFindOptions::SetRenameLimit) {

      GitDiffFindOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->rename_limit = (size_t) Nan::To<int32_t>(value).FromJust();
        }
     }

   
Nan::Persistent<Function> GitDiffFindOptions::constructor_template;
