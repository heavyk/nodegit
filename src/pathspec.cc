// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/pathspec.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/pathspec_match_list.h"
  #include "../include/diff.h"
  #include "../include/index.h"
  #include "../include/diff_delta.h"
  #include "../include/tree.h"
  #include "../include/repository.h"
  #include "../include/strarray.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitPathspec::GitPathspec(git_pathspec *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitPathspec::~GitPathspec() {
      if (this->selfFreeing) {
        git_pathspec_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                         }

  void GitPathspec::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Pathspec").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "matchDiff", MatchDiff);
            Nan::SetPrototypeMethod(tpl, "matchIndex", MatchIndex);
             Nan::SetMethod(tpl, "matchListDiffEntry", MatchListDiffEntry);
             Nan::SetMethod(tpl, "matchListEntry", MatchListEntry);
             Nan::SetMethod(tpl, "matchListEntrycount", MatchListEntrycount);
             Nan::SetMethod(tpl, "matchListFailedEntry", MatchListFailedEntry);
             Nan::SetMethod(tpl, "matchListFailedEntrycount", MatchListFailedEntrycount);
            Nan::SetPrototypeMethod(tpl, "matchTree", MatchTree);
            Nan::SetPrototypeMethod(tpl, "matchWorkdir", MatchWorkdir);
            Nan::SetPrototypeMethod(tpl, "matchesPath", MatchesPath);
             Nan::SetMethod(tpl, "create", Create);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Pathspec").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitPathspec::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitPathspec cannot be instantiated.");
     }

    GitPathspec* object = new GitPathspec(static_cast<git_pathspec *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitPathspec::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitPathspec::constructor_template), 2, argv).ToLocalChecked());
  }

  git_pathspec *GitPathspec::GetValue() {
    return this->raw;
  }

  git_pathspec **GitPathspec::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitPathspec::ClearValue() {
    this->raw = NULL;
  }

  
/*
     */
NAN_METHOD(GitPathspec::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitPathspec>(info.This())->GetValue() != NULL) {
 git_pathspec_free(
Nan::ObjectWrap::Unwrap<GitPathspec>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitPathspec>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
  
/*
  * @param Diff diff
   * @param Number flags
      * @param PathspecMatchList callback
   */
NAN_METHOD(GitPathspec::MatchDiff) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Diff diff is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number flags is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  MatchDiffBaton* baton = new MatchDiffBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_diff * from_diff;
  from_diff = Nan::ObjectWrap::Unwrap<GitDiff>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->diff = from_diff;
// start convert_from_v8 block
  uint32_t from_flags;
  from_flags = (uint32_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->flags = from_flags;
  baton->ps = Nan::ObjectWrap::Unwrap<GitPathspec>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  MatchDiffWorker *worker = new MatchDiffWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("diff", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("flags", info[1]->ToObject());
  worker->SaveToPersistent("ps", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitPathspec::MatchDiffWorker::Execute() {
  int result = git_pathspec_match_diff(
&baton->out,baton->diff,baton->flags,baton->ps    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitPathspec::MatchDiffWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitPathspecMatchList baton->out
       to = GitPathspecMatchList::New((void *)baton->out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("diff"));
      workerArguments.push(GetFromPersistent("flags"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method matchDiff has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

  
/*
  * @param Index index
   * @param Number flags
      * @param PathspecMatchList callback
   */
NAN_METHOD(GitPathspec::MatchIndex) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Index index is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number flags is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  MatchIndexBaton* baton = new MatchIndexBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_index * from_index;
  from_index = Nan::ObjectWrap::Unwrap<GitIndex>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->index = from_index;
// start convert_from_v8 block
  uint32_t from_flags;
  from_flags = (uint32_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->flags = from_flags;
  baton->ps = Nan::ObjectWrap::Unwrap<GitPathspec>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  MatchIndexWorker *worker = new MatchIndexWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("index", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("flags", info[1]->ToObject());
  worker->SaveToPersistent("ps", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitPathspec::MatchIndexWorker::Execute() {
  int result = git_pathspec_match_index(
&baton->out,baton->index,baton->flags,baton->ps    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitPathspec::MatchIndexWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitPathspecMatchList baton->out
       to = GitPathspecMatchList::New((void *)baton->out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("index"));
      workerArguments.push(GetFromPersistent("flags"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method matchIndex has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

   
/*
 * @param PathspecMatchList m
   * @param Number pos
     * @return DiffDelta  result    */
NAN_METHOD(GitPathspec::MatchListDiffEntry) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("PathspecMatchList m is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number pos is required.");
  }

// start convert_from_v8 block
  const git_pathspec_match_list * from_m;
  from_m = Nan::ObjectWrap::Unwrap<GitPathspecMatchList>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_pos;
  from_pos = (size_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   const git_diff_delta * result = git_pathspec_match_list_diff_entry(
from_m
,from_pos
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitDiffDelta result
       to = GitDiffDelta::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param PathspecMatchList m
   * @param Number pos
     * @return String  result    */
NAN_METHOD(GitPathspec::MatchListEntry) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("PathspecMatchList m is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number pos is required.");
  }

// start convert_from_v8 block
  const git_pathspec_match_list * from_m;
  from_m = Nan::ObjectWrap::Unwrap<GitPathspecMatchList>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_pos;
  from_pos = (size_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   const char * result = git_pathspec_match_list_entry(
from_m
,from_pos
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  if (result){
       to = Nan::New<String>(result).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param PathspecMatchList m
     * @return Number  result    */
NAN_METHOD(GitPathspec::MatchListEntrycount) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("PathspecMatchList m is required.");
  }

// start convert_from_v8 block
  const git_pathspec_match_list * from_m;
  from_m = Nan::ObjectWrap::Unwrap<GitPathspecMatchList>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   size_t result = git_pathspec_match_list_entrycount(
from_m
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param PathspecMatchList m
   * @param Number pos
     * @return String  result    */
NAN_METHOD(GitPathspec::MatchListFailedEntry) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("PathspecMatchList m is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number pos is required.");
  }

// start convert_from_v8 block
  const git_pathspec_match_list * from_m;
  from_m = Nan::ObjectWrap::Unwrap<GitPathspecMatchList>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_pos;
  from_pos = (size_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   const char * result = git_pathspec_match_list_failed_entry(
from_m
,from_pos
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  if (result){
       to = Nan::New<String>(result).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param PathspecMatchList m
     * @return Number  result    */
NAN_METHOD(GitPathspec::MatchListFailedEntrycount) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("PathspecMatchList m is required.");
  }

// start convert_from_v8 block
  const git_pathspec_match_list * from_m;
  from_m = Nan::ObjectWrap::Unwrap<GitPathspecMatchList>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   size_t result = git_pathspec_match_list_failed_entrycount(
from_m
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param Tree tree
   * @param Number flags
      * @param PathspecMatchList callback
   */
NAN_METHOD(GitPathspec::MatchTree) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Tree tree is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number flags is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  MatchTreeBaton* baton = new MatchTreeBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_tree * from_tree;
  from_tree = Nan::ObjectWrap::Unwrap<GitTree>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->tree = from_tree;
// start convert_from_v8 block
  uint32_t from_flags;
  from_flags = (uint32_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->flags = from_flags;
  baton->ps = Nan::ObjectWrap::Unwrap<GitPathspec>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  MatchTreeWorker *worker = new MatchTreeWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("tree", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("flags", info[1]->ToObject());
  worker->SaveToPersistent("ps", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitPathspec::MatchTreeWorker::Execute() {
  int result = git_pathspec_match_tree(
&baton->out,baton->tree,baton->flags,baton->ps    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitPathspec::MatchTreeWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitPathspecMatchList baton->out
       to = GitPathspecMatchList::New((void *)baton->out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("tree"));
      workerArguments.push(GetFromPersistent("flags"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method matchTree has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

  
/*
  * @param Repository repo
   * @param Number flags
      * @param PathspecMatchList callback
   */
NAN_METHOD(GitPathspec::MatchWorkdir) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number flags is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  MatchWorkdirBaton* baton = new MatchWorkdirBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  uint32_t from_flags;
  from_flags = (uint32_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->flags = from_flags;
  baton->ps = Nan::ObjectWrap::Unwrap<GitPathspec>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  MatchWorkdirWorker *worker = new MatchWorkdirWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("flags", info[1]->ToObject());
  worker->SaveToPersistent("ps", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitPathspec::MatchWorkdirWorker::Execute() {
  int result = git_pathspec_match_workdir(
&baton->out,baton->repo,baton->flags,baton->ps    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitPathspec::MatchWorkdirWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitPathspecMatchList baton->out
       to = GitPathspecMatchList::New((void *)baton->out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("flags"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method matchWorkdir has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

   
/*
   * @param Number flags
   * @param String path
     * @return Number  result    */
NAN_METHOD(GitPathspec::MatchesPath) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number flags is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

// start convert_from_v8 block
  uint32_t from_flags;
  from_flags = (uint32_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[1]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
   int result = git_pathspec_matches_path(
Nan::ObjectWrap::Unwrap<GitPathspec>(info.This())->GetValue()
,from_flags
,from_path
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
  * @param Strarray pathspec
     * @return Pathspec out    */
NAN_METHOD(GitPathspec::Create) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !(Nan::To<bool>(info[0]).FromJust())) {
    return Nan::ThrowError("Array, String Object, or string pathspec is required.");
  }
  git_pathspec * out = 0;
// start convert_from_v8 block
  const git_strarray * from_pathspec;

  from_pathspec = StrArrayConverter::Convert(info[0]);
// end convert_from_v8 block
 git_pathspec_new(
&out
,from_pathspec
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitPathspec out
       to = GitPathspec::New((void *)out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitPathspec::constructor_template;
 