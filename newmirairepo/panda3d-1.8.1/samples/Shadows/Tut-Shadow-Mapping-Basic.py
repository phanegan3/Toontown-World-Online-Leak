from panda3d.core import *
import sys,os
loadPrcFileData("", "prefer-parasite-buffer #f")

import direct.directbase.DirectStart
from direct.interval.IntervalGlobal import *
from direct.gui.DirectGui import OnscreenText
from direct.showbase.DirectObject import DirectObject
from direct.actor import Actor
from random import *

# Function to put instructions on the screen.
def addInstructions(pos, msg):
    return OnscreenText(text=msg, style=1, fg=(1,1,1,1), mayChange=1,
                        pos=(-1.3, pos), align=TextNode.ALeft, scale = .05, shadow=(0,0,0,1), shadowOffset=(0.1,0.1))

# Function to put title on the screen.
def addTitle(text):
    return OnscreenText(text=text, style=1, fg=(1,1,1,1),
                        pos=(1.3,-0.95), align=TextNode.ARight, scale = .07)

class World(DirectObject):
    def __init__(self):
        # Preliminary capabilities check.
    
        if (base.win.getGsg().getSupportsBasicShaders()==0):
            self.t=addTitle("Shadow Demo: Video driver reports that shaders are not supported.")
            return
        if (base.win.getGsg().getSupportsDepthTexture()==0):
            self.t=addTitle("Shadow Demo: Video driver reports that depth textures are not supported.")
            return
        
        self.inst_p = addInstructions(0.95, 'P : stop/start the Panda Rotation')
        self.inst_w = addInstructions(0.90, 'W : stop/start the Walk Cycle')
        self.inst_t = addInstructions(0.85, 'T : stop/start the Teapot')
        self.inst_l = addInstructions(0.80, 'L : move light source far or close')
        self.inst_v = addInstructions(0.75, 'V: View the Depth-Texture results')
        self.inst_x = addInstructions(0.70, 'Left/Right Arrow : switch camera angles')
    
        base.setBackgroundColor(0,0,0.2,1)
    
        base.camLens.setNearFar(1.0,10000)
        base.camLens.setFov(75)
        base.disableMouse()

        # Load the scene.
    
        floorTex=loader.loadTexture('maps/envir-ground.jpg')
        cm=CardMaker('')
        cm.setFrame(-2,2,-2,2)
        floor = render.attachNewNode(PandaNode("floor"))
        for y in range(12):
            for x in range(12):
                nn = floor.attachNewNode(cm.generate())
                nn.setP(-90)
                nn.setPos((x-6)*4, (y-6)*4, 0)
        floor.setTexture(floorTex)
        floor.flattenStrong()
    
        self.pandaAxis=render.attachNewNode('panda axis')
        self.pandaModel=Actor.Actor('panda-model',{'walk':'panda-walk4'})
        self.pandaModel.reparentTo(self.pandaAxis)
        self.pandaModel.setPos(9,0,0)
        self.pandaModel.setScale(0.01)
        self.pandaWalk = self.pandaModel.actorInterval('walk',playRate=1.8)
        self.pandaWalk.loop()
        self.pandaMovement = self.pandaAxis.hprInterval(20.0,Point3(-360,0,0),startHpr=Point3(0,0,0))
        self.pandaMovement.loop()
    
        self.teapot=loader.loadModel('teapot')
        self.teapot.reparentTo(render)
        self.teapot.setPos(0,-20,10)
        self.teapot.setShaderInput("texDisable",1,1,1,1)
        self.teapotMovement = self.teapot.hprInterval(50,Point3(0,360,360))
        self.teapotMovement.loop()
    
        self.accept('escape',sys.exit)
    
        self.accept("arrow_left", self.incrementCameraPosition, [-1])
        self.accept("arrow_right", self.incrementCameraPosition, [1])
        self.accept("p", self.toggleInterval, [self.pandaMovement])
        self.accept("P", self.toggleInterval, [self.pandaMovement])
        self.accept("t", self.toggleInterval, [self.teapotMovement])
        self.accept("T", self.toggleInterval, [self.teapotMovement])
        self.accept("w", self.toggleInterval, [self.pandaWalk])
        self.accept("W", self.toggleInterval, [self.pandaWalk])
        self.accept("v", base.bufferViewer.toggleEnable)
        self.accept("V", base.bufferViewer.toggleEnable)
        self.accept("l", self.incrementLightPosition, [1])
        self.accept("L", self.incrementLightPosition, [1])
        self.accept("o", base.oobe)
    
        self.light = render.attachNewNode(Spotlight("Spot"))
        self.light.node().setScene(render)
        self.light.node().setShadowCaster(True)
        self.light.node().showFrustum()
        self.light.node().getLens().setFov(40)
        self.light.node().getLens().setNearFar(10,100)
        render.setLight(self.light)

        self.alight = render.attachNewNode(AmbientLight("Ambient"))
        self.alight.node().setColor(Vec4(0.2, 0.2, 0.2, 1))
        render.setLight(self.alight)

        # Important! Enable the shader generator.
        render.setShaderAuto()
        
        # default values
        self.cameraSelection = 0
        self.lightSelection = 0
    
        self.incrementCameraPosition(0)
        self.incrementLightPosition(0)
    
# end of __init__

    def toggleInterval(self, ival):
        if (ival.isPlaying()):
            ival.pause()
        else:
            ival.resume()

    def incrementCameraPosition(self,n):
        self.cameraSelection = (self.cameraSelection + n) % 6
        if (self.cameraSelection == 0):
            base.cam.reparentTo(render)
            base.cam.setPos(30,-45,26)
            base.cam.lookAt(0,0,0)
            self.light.node().hideFrustum()
        if (self.cameraSelection == 1):
            base.cam.reparentTo(self.pandaModel)
            base.cam.setPos(7,-3,9)
            base.cam.lookAt(0,0,0)
            self.light.node().hideFrustum()
        if (self.cameraSelection == 2):
            base.cam.reparentTo(self.pandaModel)
            base.cam.setPos(-7,-3,9)
            base.cam.lookAt(0,0,0)
            self.light.node().hideFrustum()
        if (self.cameraSelection == 3):
            base.cam.reparentTo(render)
            base.cam.setPos(7,-23,12)
            base.cam.lookAt(self.teapot)
            self.light.node().hideFrustum()
        if (self.cameraSelection == 4):
            base.cam.reparentTo(render)
            base.cam.setPos(-7,-23,12)
            base.cam.lookAt(self.teapot)
            self.light.node().hideFrustum()
        if (self.cameraSelection == 5):
            base.cam.reparentTo(render)
            base.cam.setPos(1000,0,195)
            base.cam.lookAt(0,0,0)
            self.light.node().showFrustum()
  
    def incrementLightPosition(self,n):
        self.lightSelection = (self.lightSelection + n) % 2
        if (self.lightSelection == 0):
            self.light.setPos(0,-40,25)
            self.light.lookAt(0,-10,0)
            self.light.node().getLens().setNearFar(10,100)
        if (self.lightSelection == 1):
            self.light.setPos(0,-600,200)
            self.light.lookAt(0,-10,0)
            self.light.node().getLens().setNearFar(10,1000)
  
    def shaderSupported(self):
        return base.win.getGsg().getSupportsBasicShaders() and \
               base.win.getGsg().getSupportsDepthTexture() and \
               base.win.getGsg().getSupportsShadowFilter()
  

World()
run()
