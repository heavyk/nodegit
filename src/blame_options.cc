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
#include "../include/blame_options.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/oid.h"
 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitBlameOptions::GitBlameOptions() {
   git_blame_options wrappedValue = GIT_BLAME_OPTIONS_INIT;
   this->raw = (git_blame_options*) malloc(sizeof(git_blame_options));
  memcpy(this->raw, &wrappedValue, sizeof(git_blame_options));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitBlameOptions::GitBlameOptions(git_blame_options* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitBlameOptions::~GitBlameOptions() {
                        
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitBlameOptions::ConstructFields() {
                   Local<Object> newest_commitTemp = GitOid::New(
            &this->raw->newest_commit,
            false
          )->ToObject();
          this->newest_commit.Reset(newest_commitTemp);

             Local<Object> oldest_commitTemp = GitOid::New(
            &this->raw->oldest_commit,
            false
          )->ToObject();
          this->oldest_commit.Reset(oldest_commitTemp);

          }

void GitBlameOptions::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("BlameOptions").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("flags").ToLocalChecked(), GetFlags, SetFlags);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("minMatchCharacters").ToLocalChecked(), GetMinMatchCharacters, SetMinMatchCharacters);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("newestCommit").ToLocalChecked(), GetNewestCommit, SetNewestCommit);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("oldestCommit").ToLocalChecked(), GetOldestCommit, SetOldestCommit);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("minLine").ToLocalChecked(), GetMinLine, SetMinLine);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("maxLine").ToLocalChecked(), GetMaxLine, SetMaxLine);
   
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("BlameOptions").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitBlameOptions::JSNewFunction) {
  GitBlameOptions* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitBlameOptions();
  }
  else {
    instance = new GitBlameOptions(static_cast<git_blame_options*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitBlameOptions::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitBlameOptions::constructor_template), 2, argv).ToLocalChecked());
}

git_blame_options *GitBlameOptions::GetValue() {
  return this->raw;
}

git_blame_options **GitBlameOptions::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitBlameOptions::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitBlameOptions::GetVersion) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitBlameOptions::SetVersion) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitBlameOptions::GetFlags) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->flags));
     }

    NAN_SETTER(GitBlameOptions::SetFlags) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->flags = (uint32_t) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitBlameOptions::GetMinMatchCharacters) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->min_match_characters));
     }

    NAN_SETTER(GitBlameOptions::SetMinMatchCharacters) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->min_match_characters = (uint16_t) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitBlameOptions::GetNewestCommit) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->newest_commit));

     }

    NAN_SETTER(GitBlameOptions::SetNewestCommit) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

        Local<Object> newest_commit(value->ToObject());

        wrapper->newest_commit.Reset(newest_commit);

        wrapper->raw->newest_commit = *  Nan::ObjectWrap::Unwrap<GitOid>(newest_commit->ToObject())->GetValue() ;

     }

      NAN_GETTER(GitBlameOptions::GetOldestCommit) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->oldest_commit));

     }

    NAN_SETTER(GitBlameOptions::SetOldestCommit) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

        Local<Object> oldest_commit(value->ToObject());

        wrapper->oldest_commit.Reset(oldest_commit);

        wrapper->raw->oldest_commit = *  Nan::ObjectWrap::Unwrap<GitOid>(oldest_commit->ToObject())->GetValue() ;

     }

      NAN_GETTER(GitBlameOptions::GetMinLine) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->min_line));
     }

    NAN_SETTER(GitBlameOptions::SetMinLine) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->min_line = (uint32_t) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitBlameOptions::GetMaxLine) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->max_line));
     }

    NAN_SETTER(GitBlameOptions::SetMaxLine) {

      GitBlameOptions *wrapper = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->max_line = (uint32_t) Nan::To<int32_t>(value).FromJust();
        }
     }

   
Nan::Persistent<Function> GitBlameOptions::constructor_template;
