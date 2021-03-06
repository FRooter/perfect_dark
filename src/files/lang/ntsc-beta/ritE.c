#include <ultra64.h>

char *lang[] = {
	/*  0*/ "|Background - \n\nTrent Easton's plan to abduct the President is in motion. The Carrington Institute response hinges on removing the President from Air Force One before Trent can do the same.\n\n|Carrington - \n\nTime is short, Joanna. In order to foil Trent's plan, you have to get the President off the plane. That means convincing him of Trent's betrayal, which in turn means getting the evidence from the baggage hold and showing it to the President.\n\n|Objective One: - Locate and Retrieve Equipment\n\nFind the equipment hidden in the baggage hold at the bottom of the aircraft and get it back. Remember that Presidential security are neutral and are not to be harmed.\n\n|Objective Two: - Locate President\n\nThe exact whereabouts of the Presidential office are not known. Once you find the office, present the evidence to the President. Make sure you get there before Trent does, or you can be sure he will manipulate the situation to his advantage.\n\n|Objective Three: - Get President to Escape Capsule\n\nThere is an emergency escape capsule on the lowest deck of the aircraft. Escort the President to the capsule, ensuring that no harm comes to him.\n\n|Objective Four: - Secure Air Force One Flight Path\n\nThe specifics of Trent's plan are not known, but it is believed that the flight crew will be in danger. Get to the cockpit and make sure of their well-being. If the worst has happened, then activate the autopilot.\n\n|Objective Five: - Detach UFO From Air Force One\n\nGet that umbilical connector off Air Force One! The quickest way to do it would be to detonate a mine in the connector itself. \n\nEND\n",
	/*  1*/ "AIR FORCE ONE\n",
	/*  2*/ "|Background - \n\nTrent Easton's plan to abduct the President is in motion. The Carrington Institute response hinges on removing the President from Air Force One before Trent can do the same.\n\n|Carrington - \n\nTime is short, Joanna. In order to foil Trent's plan, you have to get the President off the plane. That means convincing him of Trent's betrayal, which in turn means getting the evidence from the baggage hold and showing it to the President.\n\n|Objective One: - Locate and Retrieve Equipment\n\nFind the equipment hidden in the baggage hold at the bottom of the aircraft and get it back. Remember thatPresidential security are neutral and are not to beharmed.\n\n|Objective Two: - Locate President\n\nThe exact whereabouts of the Presidential office are not known. Once you find the office, present the evidence to the President. Make sure you get there before Trent does, or you can be sure he will manipulate the situation to his advantage.\n\n|Objective Three: - Get President to Escape Capsule\n\nThere is an emergency escape capsule on the lowest deck of the aircraft. Escort the President to the capsule, ensuring that no harm comes to him.\n\n|Objective Four: - Detach UFO From Air Force One\n\nGet that umbilical connector off Air Force One! The quickest way to do it would be to detonate a mine in the connector itself. \n\nEND\n",
	/*  3*/ "|Background - \n\nTrent Easton's plan to abduct the President is in motion. The Carrington Institute response hinges on removing the President from Air Force One before Trent can do the same.\n\n|Carrington - \n\nTime is short, Joanna. In order to foil Trent's plan, you have to get the President off the plane. That means convincing him of Trent's betrayal, which in turn means showing the evidence to the President.\n\n|Objective One: - Locate President\n\nThe exact whereabouts of the Presidential office are not known. Once you find the office, present the evidence to the President. Make sure you get there before Trent does, or you can be sure he will manipulate the situation to his advantage.\n\n|Objective Two: - Get President to Escape Capsule\n\nThere is an emergency escape capsule on the lowest deck of the aircraft. Escort the President to the capsule, ensuring that no harm comes to him.\n\n|Objective Three: - Detach UFO From Air Force One\n\nGet that umbilical connector off Air Force One! The quickest way to do it would be to detonate a mine in the connector itself. \n\nEND\n",
	/*  4*/ "\n",
	/*  5*/ "Locate and retrieve equipment\n",
	/*  6*/ "Locate President\n",
	/*  7*/ "Get President to escape capsule\n",
	/*  8*/ "Secure Air Force One flight path\n",
	/*  9*/ "Detach UFO from Air Force One\n",
	/* 10*/ "Obtain Suitcase.\n",
	/* 11*/ "\n",
	/* 12*/ "Suitcase\n",
	/* 13*/ "Suitcase\n",
	/* 14*/ "Picked up a Suitcase.\n",
	/* 15*/ "Obtain Crossbow.\n",
	/* 16*/ "\n",
	/* 17*/ "Crossbow\n",
	/* 18*/ "Crossbow\n",
	/* 19*/ "Picked up a Crossbow.\n",
	/* 20*/ "Too many neutral casualties inflicted.\n",
	/* 21*/ "UFO attachment damaged.\n",
	/* 22*/ "Unable to detach UFO.\n",
	/* 23*/ "Autopilot has been activated.\n",
	/* 24*/ "Air Force One has been stabilized.\n",
	/* 25*/ "Autopilot systems have been destroyed.\n",
	/* 26*/ "The President has been incapacitated.\n",
	/* 27*/ "Pilots have been killed.\n",
	/* 28*/ "Pilots have been saved.\n",
	/* 29*/ "Air Force One is about to crash.\n",
	/* 30*/ "Obtain remote mine.\n",
	/* 31*/ "\n",
	/* 32*/ "Remote mine\n",
	/* 33*/ "Remote mine\n",
	/* 34*/ "Picked up a remote mine.\n",
	/* 35*/ "Who are you, young lady?\n",
	/* 36*/ "Security, SECURITY!!\n",
	/* 37*/ "Mr. President, you're in danger. Trent is trying to \nkidnap you.\n",
	/* 38*/ "What the hell was that!\n",
	/* 39*/ "We have to get you to the escape pod.  \nFollow me.\n",
	/* 40*/ "You can't make accusations like that without evidence.\n I assume that you have some?\n",
	/* 41*/ "This is a recording of a meeting between\nTrent and the other conspirators.\n",
	/* 42*/ "Seems overwhelming... I'm in your hands.\nWhat do we do now?\n",
	/* 43*/ "Hey, that's not...\n",
	/* 44*/ "It's an intruder...\n",
	/* 45*/ "How the hell did you get on board?\n",
	/* 46*/ "Now, let's retrieve the evidence.\n",
	/* 47*/ "The President's room is on this \nlevel, Joanna.\n",
	/* 48*/ "Something's wrong... You have to get to the cockpit!\n",
	/* 49*/ "Maybe a mine will detach the UFO.\n",
	/* 50*/ "\n",
	/* 51*/ "\n",
	/* 52*/ "Adrenaline pill\n",
	/* 53*/ "Adrenaline pill\n",
	/* 54*/ "Picked up an adrenaline pill.\n",
	/* 55*/ "\n",
	/* 56*/ "\n",
	/* 57*/ "Key card\n",
	/* 58*/ "Key card\n",
	/* 59*/ "Picked up a key card.\n",
	/* 60*/ "Cargo bay has been lowered.\n",
	/* 61*/ "Cargo bay has been raised.\n",
	/* 62*/ "Mission critical object has been destroyed.\n",
	/* 63*/ "Access denied - lift key card required.\n",
	/* 64*/ "\n",
	/* 65*/ "\n",
	/* 66*/ "Lift key card\n",
	/* 67*/ "Lift key card\n",
	/* 68*/ "Picked up a lift key card.\n",
	/* 69*/ "Timed mine has been wasted.\n",
	/* 70*/ "Ha, Ha, Ha, Ha, Ha.\n",
	/* 71*/ "You'll never save him now.\n",
	/* 72*/ "The President is under attack.\n",
	/* 73*/ "Have you thought any more about that proposal I gave you, sir?\n",
	/* 74*/ "My answer remains the same... I'm sorry Trent, but no. I won't loan the Pelagic II to dataDyne. Now please, can we move on to other matters?\n",
	/* 75*/ "But this is a golden opportunity to show that America has faith in its industries and will back them...\n",
	/* 76*/ "Damn it man! I say no and I mean no! I'm not gonna change my mind on this! I need my advisors to be unbiased, and recently you've not been giving me the impartiality I require. Let it go, and we'll say no more. This is your last chance.\n",
	/* 77*/ "As you wish, sir.\n",
	/* 78*/ "My last chance? Ha! You fool. That was yours.\n",
	/* 79*/ "Elvis! Elvis! I can't detach that tube from the fuselage! Can you take it out?\n",
	/* 80*/ "Piece of cake, Joanna. Watch this!\n",
	/* 81*/ "Uh-oh.\n",
	/* 82*/ "Watch what? Will you stop playing around and shoot!\n",
	/* 83*/ "Out of options... Joanna, brace yourself for impact!\n",
	/* 84*/ "The pilots have stablised Air Force One.\n",
	/* 85*/ NULL,
	/* 86*/ NULL,
	/* 87*/ NULL,
};
