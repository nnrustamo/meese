//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MeeseTestApp.h"
#include "MeeseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
MeeseTestApp::validParams()
{
  InputParameters params = MeeseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

MeeseTestApp::MeeseTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MeeseTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MeeseTestApp::~MeeseTestApp() {}

void
MeeseTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MeeseApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MeeseTestApp"});
    Registry::registerActionsTo(af, {"MeeseTestApp"});
  }
}

void
MeeseTestApp::registerApps()
{
  registerApp(MeeseApp);
  registerApp(MeeseTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MeeseTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MeeseTestApp::registerAll(f, af, s);
}
extern "C" void
MeeseTestApp__registerApps()
{
  MeeseTestApp::registerApps();
}
