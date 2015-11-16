// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/branch.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/reference.h"
  #include "../include/repository.h"
  #include "../include/commit.h"
  #include "../include/annotated_commit.h"
  #include "../include/branch_iterator.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitBranch::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "create", Create);
         Nan::SetMethod(object, "createFromAnnotated", CreateFromAnnotated);
         Nan::SetMethod(object, "delete", Delete);
         Nan::SetMethod(object, "isHead", IsHead);
         Nan::SetMethod(object, "iteratorNew", IteratorNew);
         Nan::SetMethod(object, "lookup", Lookup);
         Nan::SetMethod(object, "move", Move);
         Nan::SetMethod(object, "name", Name);
         Nan::SetMethod(object, "setUpstream", SetUpstream);
         Nan::SetMethod(object, "upstream", Upstream);
  
    Nan::Set(target, Nan::New<String>("Branch").ToLocalChecked(), object);
  }

 
/*
  * @param Repository repo
   * @param String branch_name
   * @param Commit target
   * @param Number force
    * @param Reference callback
   */
NAN_METHOD(GitBranch::Create) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String branch_name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("Commit target is required.");
  }

  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CreateBaton* baton = new CreateBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_branch_name;

  String::Utf8Value branch_name(info[1]->ToString());
  from_branch_name = (const char *) strdup(*branch_name);
// end convert_from_v8 block
  baton->branch_name = from_branch_name;
// start convert_from_v8 block
  const git_commit * from_target;
  from_target = Nan::ObjectWrap::Unwrap<GitCommit>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->target = from_target;
// start convert_from_v8 block
  int from_force;
    if (info[3]->IsNumber()) {
  from_force = (int)   info[3]->ToNumber()->Value();
  }
  else {
    from_force = 0;
  }
// end convert_from_v8 block
  baton->force = from_force;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[4]));
  CreateWorker *worker = new CreateWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("branch_name", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("target", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("force", info[3]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitBranch::CreateWorker::Execute() {
  int result = git_branch_create(
&baton->out,baton->repo,baton->branch_name,baton->target,baton->force    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitBranch::CreateWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRefs baton->out
       to = GitRefs::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("branch_name"));
      workerArguments.push(GetFromPersistent("target"));
      workerArguments.push(GetFromPersistent("force"));
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
        Local<v8::Object> err = Nan::Error("Method create has thrown an error.")->ToObject();
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

  free((void *)baton->branch_name);

  delete baton;
}

   
/*
  * @param Repository repository
   * @param String branch_name
   * @param AnnotatedCommit commit
   * @param Number force
     * @return Reference ref_out    */
NAN_METHOD(GitBranch::CreateFromAnnotated) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repository is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String branch_name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("AnnotatedCommit commit is required.");
  }

  git_reference * ref_out = 0;
// start convert_from_v8 block
  git_repository * from_repository;
  from_repository = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_branch_name;

  String::Utf8Value branch_name(info[1]->ToString());
  from_branch_name = (const char *) strdup(*branch_name);
// end convert_from_v8 block
// start convert_from_v8 block
  const git_annotated_commit * from_commit;
  from_commit = Nan::ObjectWrap::Unwrap<GitAnnotatedCommit>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  int from_force;
    if (info[3]->IsNumber()) {
  from_force = (int)   info[3]->ToNumber()->Value();
  }
  else {
    from_force = 0;
  }
// end convert_from_v8 block
   int result = git_branch_create_from_annotated(
&ref_out
,from_repository
,from_branch_name
,from_commit
,from_force
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (ref_out != NULL) {
    // GitRefs ref_out
       to = GitRefs::New((void *)ref_out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param Reference branch
     * @return Number  result    */
NAN_METHOD(GitBranch::Delete) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Reference branch is required.");
  }

// start convert_from_v8 block
  git_reference * from_branch;
  from_branch = Nan::ObjectWrap::Unwrap<GitRefs>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_branch_delete(
from_branch
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param Reference branch
     * @return Number  result    */
NAN_METHOD(GitBranch::IsHead) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Reference branch is required.");
  }

// start convert_from_v8 block
  const git_reference * from_branch;
  from_branch = Nan::ObjectWrap::Unwrap<GitRefs>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_branch_is_head(
from_branch
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param Repository repo
   * @param Number list_flags
    * @param BranchIterator callback
   */
NAN_METHOD(GitBranch::IteratorNew) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number list_flags is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  IteratorNewBaton* baton = new IteratorNewBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  git_branch_t from_list_flags;
  from_list_flags = (git_branch_t)  (int) info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->list_flags = from_list_flags;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  IteratorNewWorker *worker = new IteratorNewWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("list_flags", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitBranch::IteratorNewWorker::Execute() {
  int result = git_branch_iterator_new(
&baton->out,baton->repo,baton->list_flags    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitBranch::IteratorNewWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitBranchIterator baton->out
       to = GitBranchIterator::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("list_flags"));
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
        Local<v8::Object> err = Nan::Error("Method iteratorNew has thrown an error.")->ToObject();
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
   * @param String branch_name
   * @param Number branch_type
    * @param Reference callback
   */
NAN_METHOD(GitBranch::Lookup) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String branch_name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number branch_type is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  LookupBaton* baton = new LookupBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_branch_name;

  String::Utf8Value branch_name(info[1]->ToString());
  from_branch_name = (const char *) strdup(*branch_name);
// end convert_from_v8 block
  baton->branch_name = from_branch_name;
// start convert_from_v8 block
  git_branch_t from_branch_type;
  from_branch_type = (git_branch_t)  (int) info[2]->ToNumber()->Value();
// end convert_from_v8 block
  baton->branch_type = from_branch_type;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  LookupWorker *worker = new LookupWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("branch_name", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("branch_type", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitBranch::LookupWorker::Execute() {
  int result = git_branch_lookup(
&baton->out,baton->repo,baton->branch_name,baton->branch_type    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitBranch::LookupWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRefs baton->out
       to = GitRefs::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("branch_name"));
      workerArguments.push(GetFromPersistent("branch_type"));
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
        Local<v8::Object> err = Nan::Error("Method lookup has thrown an error.")->ToObject();
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

  free((void *)baton->branch_name);

  delete baton;
}

  
/*
  * @param Reference branch
   * @param String new_branch_name
   * @param Number force
    * @param Reference callback
   */
NAN_METHOD(GitBranch::Move) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Reference branch is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String new_branch_name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number force is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  MoveBaton* baton = new MoveBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_reference * from_branch;
  from_branch = Nan::ObjectWrap::Unwrap<GitRefs>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->branch = from_branch;
// start convert_from_v8 block
  const char * from_new_branch_name;

  String::Utf8Value new_branch_name(info[1]->ToString());
  from_new_branch_name = (const char *) strdup(*new_branch_name);
// end convert_from_v8 block
  baton->new_branch_name = from_new_branch_name;
// start convert_from_v8 block
  int from_force;
  from_force = (int)   info[2]->ToNumber()->Value();
// end convert_from_v8 block
  baton->force = from_force;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  MoveWorker *worker = new MoveWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("branch", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("new_branch_name", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("force", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitBranch::MoveWorker::Execute() {
  int result = git_branch_move(
&baton->out,baton->branch,baton->new_branch_name,baton->force    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitBranch::MoveWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRefs baton->out
       to = GitRefs::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("branch"));
      workerArguments.push(GetFromPersistent("new_branch_name"));
      workerArguments.push(GetFromPersistent("force"));
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
        Local<v8::Object> err = Nan::Error("Method move has thrown an error.")->ToObject();
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

  free((void *)baton->new_branch_name);

  delete baton;
}

  
/*
  * @param Reference ref
    * @param String callback
   */
NAN_METHOD(GitBranch::Name) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Reference ref is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  NameBaton* baton = new NameBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const git_reference * from_ref;
  from_ref = Nan::ObjectWrap::Unwrap<GitRefs>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->ref = from_ref;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  NameWorker *worker = new NameWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("ref", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitBranch::NameWorker::Execute() {
  int result = git_branch_name(
&baton->out,baton->ref    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitBranch::NameWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  if (baton->out){
       to = Nan::New<String>(baton->out).ToLocalChecked();
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
      workerArguments.push(GetFromPersistent("ref"));
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
        Local<v8::Object> err = Nan::Error("Method name has thrown an error.")->ToObject();
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

  free((void *)baton->out);

  delete baton;
}

   
/*
 * @param Reference branch
   * @param String upstream_name
     * @return Number  result    */
NAN_METHOD(GitBranch::SetUpstream) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Reference branch is required.");
  }

// start convert_from_v8 block
  git_reference * from_branch;
  from_branch = Nan::ObjectWrap::Unwrap<GitRefs>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_upstream_name;
    if (info[1]->IsString()) {

  String::Utf8Value upstream_name(info[1]->ToString());
  from_upstream_name = (const char *) strdup(*upstream_name);
  }
  else {
    from_upstream_name = 0;
  }
// end convert_from_v8 block
   int result = git_branch_set_upstream(
from_branch
,from_upstream_name
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
  * @param Reference branch
     * @return Reference out    */
NAN_METHOD(GitBranch::Upstream) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Reference branch is required.");
  }

  git_reference * out = 0;
// start convert_from_v8 block
  const git_reference * from_branch;
  from_branch = Nan::ObjectWrap::Unwrap<GitRefs>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
 git_branch_upstream(
&out
,from_branch
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitRefs out
       to = GitRefs::New((void *)out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitBranch::constructor_template;
 