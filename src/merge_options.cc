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
#include "../include/merge_options.h"
#include "../include/functions/sleep_for_ms.h"

 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitMergeOptions::GitMergeOptions() {
   git_merge_options wrappedValue = GIT_MERGE_OPTIONS_INIT;
   this->raw = (git_merge_options*) malloc(sizeof(git_merge_options));
  memcpy(this->raw, &wrappedValue, sizeof(git_merge_options));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitMergeOptions::GitMergeOptions(git_merge_options* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitMergeOptions::~GitMergeOptions() {
                   
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitMergeOptions::ConstructFields() {
                 }

void GitMergeOptions::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("MergeOptions").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("treeFlags").ToLocalChecked(), GetTreeFlags, SetTreeFlags);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("renameThreshold").ToLocalChecked(), GetRenameThreshold, SetRenameThreshold);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("targetLimit").ToLocalChecked(), GetTargetLimit, SetTargetLimit);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("fileFavor").ToLocalChecked(), GetFileFavor, SetFileFavor);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("fileFlags").ToLocalChecked(), GetFileFlags, SetFileFlags);
   
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("MergeOptions").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitMergeOptions::JSNewFunction) {
  GitMergeOptions* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitMergeOptions();
  }
  else {
    instance = new GitMergeOptions(static_cast<git_merge_options*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitMergeOptions::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitMergeOptions::constructor_template), 2, argv).ToLocalChecked());
}

git_merge_options *GitMergeOptions::GetValue() {
  return this->raw;
}

git_merge_options **GitMergeOptions::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitMergeOptions::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitMergeOptions::GetVersion) {

      GitMergeOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitMergeOptions::SetVersion) {

      GitMergeOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitMergeOptions::GetTreeFlags) {

      GitMergeOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info.This());

        info.GetReturnValue().Set(Nan::New((int)wrapper->GetValue()->tree_flags));

     }

    NAN_SETTER(GitMergeOptions::SetTreeFlags) {

      GitMergeOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info.This());

        if (value->IsNumber()) {
          wrapper->GetValue()->tree_flags = (git_merge_tree_flag_t) Nan::To<int32_t>(value).FromJust();
        }

     }

      NAN_GETTER(GitMergeOptions::GetRenameThreshold) {

      GitMergeOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->rename_threshold));
     }

    NAN_SETTER(GitMergeOptions::SetRenameThreshold) {

      GitMergeOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->rename_threshold = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitMergeOptions::GetTargetLimit) {

      GitMergeOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->target_limit));
     }

    NAN_SETTER(GitMergeOptions::SetTargetLimit) {

      GitMergeOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->target_limit = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitMergeOptions::GetFileFavor) {

      GitMergeOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info.This());

        info.GetReturnValue().Set(Nan::New((int)wrapper->GetValue()->file_favor));

     }

    NAN_SETTER(GitMergeOptions::SetFileFavor) {

      GitMergeOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info.This());

        if (value->IsNumber()) {
          wrapper->GetValue()->file_favor = (git_merge_file_favor_t) Nan::To<int32_t>(value).FromJust();
        }

     }

      NAN_GETTER(GitMergeOptions::GetFileFlags) {

      GitMergeOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->file_flags));
     }

    NAN_SETTER(GitMergeOptions::SetFileFlags) {

      GitMergeOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->file_flags = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

   
Nan::Persistent<Function> GitMergeOptions::constructor_template;
