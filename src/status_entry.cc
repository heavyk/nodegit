// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/status_entry.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/diff_delta.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitStatusEntry::GitStatusEntry(git_status_entry *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitStatusEntry::~GitStatusEntry() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitStatusEntry::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("StatusEntry").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "status", Status);
         Nan::SetPrototypeMethod(tpl, "headToIndex", HeadToIndex);
         Nan::SetPrototypeMethod(tpl, "indexToWorkdir", IndexToWorkdir);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("StatusEntry").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitStatusEntry::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitStatusEntry cannot be instantiated.");
     }

    GitStatusEntry* object = new GitStatusEntry(static_cast<git_status_entry *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitStatusEntry::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitStatusEntry::constructor_template), 2, argv).ToLocalChecked());
  }

  git_status_entry *GitStatusEntry::GetValue() {
    return this->raw;
  }

  git_status_entry **GitStatusEntry::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitStatusEntry::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitStatusEntry::Status) {
      Local<v8::Value> to;

       git_status_t
         status =
         Nan::ObjectWrap::Unwrap<GitStatusEntry>(info.This())->GetValue()->status;
 // start convert_to_v8 block
     to = Nan::New<Number>( status);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitStatusEntry::HeadToIndex) {
      Local<v8::Value> to;

       git_diff_delta *
          head_to_index =
          Nan::ObjectWrap::Unwrap<GitStatusEntry>(info.This())->GetValue()->head_to_index;
 // start convert_to_v8 block
  
  if (head_to_index != NULL) {
    // GitDiffDelta head_to_index
       to = GitDiffDelta::New((void *)head_to_index, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitStatusEntry::IndexToWorkdir) {
      Local<v8::Value> to;

       git_diff_delta *
          index_to_workdir =
          Nan::ObjectWrap::Unwrap<GitStatusEntry>(info.This())->GetValue()->index_to_workdir;
 // start convert_to_v8 block
  
  if (index_to_workdir != NULL) {
    // GitDiffDelta index_to_workdir
       to = GitDiffDelta::New((void *)index_to_workdir, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitStatusEntry::constructor_template;
 