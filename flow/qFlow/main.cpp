/* This file is part of the KDE project
   Copyright (C)  2006 Peter Simonsson <peter.simonsson@gmail.com>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

//#include <kcmdlineargs.h>

#include <KoApplication.h>

#include "plugins/defaultTools/DefaultToolsPlugin.h"
#include "plugins/dockers/DockersPlugin.h"
#include "plugins/pathshapes/PathShapesPlugin.h"
#include "plugins/stencilbox/StencilBoxPlugin.h"
#include "plugins/pictureshape/PictureShapePlugin.h"
#include "plugins/artistictextshape/ArtisticTextShapePlugin.h"

//#include "plugins/textshape/TextShapePlugin.h"
//#include "plugins/variables/VariablesPlugin.h"

#include "FlowAboutData.h"

#include <QFile>
#include <QTextStream>

#include "FlowPart.h"
#include "FlowDocument.h"
#include "KoDocumentEntry.h"

#include "KoDockRegistry.h"
#include "FlowFactory.h"

//extern "C" KDE_EXPORT int kdemain( int argc, char **argv )
int main( int argc, char **argv )
{
	QVariantList variantList;

	DefaultToolsPlugin(0, variantList);

	DockersPlugin(0, variantList);

	PathShapesPlugin(0, variantList);

	StencilBoxPlugin(0, variantList);

	ArtisticTextShapePlugin(0, variantList);

	PictureShapePlugin(0, variantList);

	//TextShapePlugin(0, variantList);

	//VariablesPlugin(0, variantList);

	KoPluginRegistry::instance()->add(new FlowFactory());

  //KAboutData *about = newFlowAboutData();
  //KCmdLineArgs::init( argc, argv, about );

  //KCmdLineOptions options;
  //options.add("+[file]", ki18n("File to open"));
  //KCmdLineArgs::addCmdLineOptions( options );

  KoApplication app(argc, argv);

  if (!app.start())
      return 1;
  app.exec();

  return 0;
}
