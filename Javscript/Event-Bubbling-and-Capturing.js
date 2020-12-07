/*
Event Bubbling -> follow bottom up approach (bubble ups)
so in it first child->parent->grandparent eventListener call ups

Event Capturing/Trickling -> follow top down
so in this grandparent->parent->child eventListener called

addEventListener('action', ()=>{

}, capture_varibale)

1. if not present -> bubbling
2. true -> capture
3. false -> bubbling
to stop this we use stopPropagation() Method
*/
