// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/describe_options.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitDescribeOptions::GitDescribeOptions(git_describe_options *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitDescribeOptions::~GitDescribeOptions() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDescribeOptions::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("DescribeOptions").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "version", Version);
         Nan::SetPrototypeMethod(tpl, "maxCandidatesTags", MaxCandidatesTags);
         Nan::SetPrototypeMethod(tpl, "describeStrategy", DescribeStrategy);
         Nan::SetPrototypeMethod(tpl, "pattern", Pattern);
         Nan::SetPrototypeMethod(tpl, "onlyFollowFirstParent", OnlyFollowFirstParent);
         Nan::SetPrototypeMethod(tpl, "showCommitOidAsFallback", ShowCommitOidAsFallback);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("DescribeOptions").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitDescribeOptions::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitDescribeOptions cannot be instantiated.");
     }

    GitDescribeOptions* object = new GitDescribeOptions(static_cast<git_describe_options *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitDescribeOptions::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitDescribeOptions::constructor_template), 2, argv).ToLocalChecked());
  }

  git_describe_options *GitDescribeOptions::GetValue() {
    return this->raw;
  }

  git_describe_options **GitDescribeOptions::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitDescribeOptions::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitDescribeOptions::Version) {
      Local<v8::Value> to;

       unsigned int
         version =
         Nan::ObjectWrap::Unwrap<GitDescribeOptions>(info.This())->GetValue()->version;
 // start convert_to_v8 block
     to = Nan::New<Number>( version);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDescribeOptions::MaxCandidatesTags) {
      Local<v8::Value> to;

       unsigned int
         max_candidates_tags =
         Nan::ObjectWrap::Unwrap<GitDescribeOptions>(info.This())->GetValue()->max_candidates_tags;
 // start convert_to_v8 block
     to = Nan::New<Number>( max_candidates_tags);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDescribeOptions::DescribeStrategy) {
      Local<v8::Value> to;

       unsigned int
         describe_strategy =
         Nan::ObjectWrap::Unwrap<GitDescribeOptions>(info.This())->GetValue()->describe_strategy;
 // start convert_to_v8 block
     to = Nan::New<Number>( describe_strategy);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDescribeOptions::Pattern) {
      Local<v8::Value> to;

       const char *
         pattern =
         Nan::ObjectWrap::Unwrap<GitDescribeOptions>(info.This())->GetValue()->pattern;
 // start convert_to_v8 block
  if (pattern){
       to = Nan::New<String>(pattern).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDescribeOptions::OnlyFollowFirstParent) {
      Local<v8::Value> to;

       int
         only_follow_first_parent =
         Nan::ObjectWrap::Unwrap<GitDescribeOptions>(info.This())->GetValue()->only_follow_first_parent;
 // start convert_to_v8 block
     to = Nan::New<Number>( only_follow_first_parent);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDescribeOptions::ShowCommitOidAsFallback) {
      Local<v8::Value> to;

       int
         show_commit_oid_as_fallback =
         Nan::ObjectWrap::Unwrap<GitDescribeOptions>(info.This())->GetValue()->show_commit_oid_as_fallback;
 // start convert_to_v8 block
     to = Nan::New<Number>( show_commit_oid_as_fallback);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitDescribeOptions::constructor_template;
 