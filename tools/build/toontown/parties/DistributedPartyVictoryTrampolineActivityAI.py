from direct.directnotify import DirectNotifyGlobal
from toontown.parties.DistributedPartyTrampolineActivityAI import DistributedPartyTrampolineActivityAI

class DistributedPartyVictoryTrampolineActivityAI(DistributedPartyTrampolineActivityAI):
    notify = DirectNotifyGlobal.directNotify.newCategory("DistributedPartyVictoryTrampolineActivityAI")

