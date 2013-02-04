// load data
var problems;
var problemsOrig;
var savedInput = new Array();
var savedOutput = new Array();
var currentlyOpen = new Array();
var lastInput = '';
var lastInputChange = false;
	
function updateTable() {
	new Ajax.Request('/db_to_json.php',
	{
		method:'get',
		onSuccess: function(transport) {
			problems = transport.responseText.evalJSON();
			problemsOrig = transport.responseText.evalJSON();
			generateList();
			filter_activity(); // start filtering search-box
		}
	});
}

function generateList() {

	var output = '<table width="100%"><tr class="tr1"><th width="5%"><a href="#" onClick="sortBy(0)">ID</a></th><th width="30%"><a href="#" onClick="sortBy(1)">Title</a></th><th><a href="#" onClick="sortBy(2)">Keyword</a></th><th>Links</th></tr>';

	for(i=0; i<problems.length; i++) {
		var id=problems[i][0];
		var title=problems[i][1];
		var keyword=problems[i][2];
		
		var link_problem = '<a style="margin-right: 4px"  href="http://icpcres.ecs.baylor.edu/onlinejudge/external/'+id.slice(0,id.length-2)+'/'+id+'.html" title="Problem"><img src="icon_problem.png" width="15" height="16" alt="Problem" title="Problem" /></a>';
		
		
//		var link_stats = '<a title="Statistics" href="http://online-judge.uva.es/p/problemstatnew.php?prob='+id+'"><img style="margin-top: 3px" src="icon_stats.png" width="16" height="16" alt="Statistics" title="Statistics" /></a>'
		var link_stats = '<a title="Statistics" href="/gotouvastats.php?id='+id+'"><img style="margin-top: 3px" src="icon_stats.png" width="16" height="16" alt="Statistics" title="Statistics" /></a>';
		
		var link_generate = '<a style="margin-right: 5px" onClick="toggleHidden('+id+')" title="Generate output" href="#'+id+'"><img style="margin-top: 0px" src="icon_generate.png" width="18" height="18" alt="Generate output" title="Generate output" /></a>'
		
		output += '<tr class="'+(i%2?'tr1':'tr2')+'"><td class="link" onclick="toggleHidden('+id+')">' + id + '</td><td onclick="toggleHidden('+id+')" class="link">' + title + '</td><td onclick="toggleHidden('+id+')" class="link">' + keyword + '</td><td style="width: 60px">'+link_generate+link_problem+link_stats+'</td></tr>' + '<tr class="generator"><td colspan="4" style="padding: 0px; margin: 0px;"><div id="generator_'+id+'" style="display: none"></div></td></tr>';
	}
	output += "</table>";
	
	$('problems').innerHTML = output;
	
	// update counter
	if (problemsOrig.length == problems.length)
		$('no_problems').innerHTML = problemsOrig.length;
	else
		$('no_problems').innerHTML = problems.length + '/' + problemsOrig.length;
}

function sortBy(column) {
	switch(column) {
		case 0:
			problems.sort(sortByID);
			break;
		case 1:
			problems.sort(sortByTitle);
			break;
		case 2:
			problems.sort(sortByKeyword);
			break;
	}
	generateList();
}

function sortByID(a,b) {
	return doSort(a,b,0);
}

function sortByTitle(a,b) {
	return doSort(a,b,1);
}

function sortByKeyword(a,b) {
	return doSort(a,b,2);
}

function doSort(a,b,column) {
	if (column==0) {
		return a[0]-b[0];
	}
	var c = a[column].toUpperCase();
	var d = b[column].toUpperCase();
	
	if (c<d)
	  return -1;
	else if (c>d)
	  return 1;
	return 0;
}

function filterProblems(filter) {

	var newI = 0;
	problems.length = 0;
	
	var filters = filter.split(' ');

	for(i=0; i<problemsOrig.length; i++) {
		var wordsFound = 0;
		for(j=0; j<filters.length; j++) {
			var testKey = problemsOrig[i][2].toUpperCase().indexOf(filters[j].toUpperCase()) > -1;
			var testTitle = problemsOrig[i][1].toUpperCase().indexOf(filters[j].toUpperCase()) > -1;
			var testID = problemsOrig[i][0].toUpperCase().indexOf(filters[j].toUpperCase()) > -1;
			
			if(testKey || testTitle || testID) {
				wordsFound++;
			}
		}
		
		if (wordsFound==filters.length)
			problems[newI++] = problemsOrig[i];
	}
	
	generateList();
}

function hiddenForm(id) {
	var html = '<form enctype="multipart/form-data" class="tr1" style="position: relative" method="post" target="compiler" action="/uploader.php" name="form_'+id+'" id="form_'+id+'">'+
	'<input type="hidden" name="id" value="'+id+'" />'+
	'<div id="lightbox'+id+'" class="lightbox"></div>'+
	'<table class="generator_table">'+
	'<tr><th width="50%">Input:</th><th>Output:</th></tr>'+
	'<tr><td><textarea title="Tip: You can submit directly from this field by hitting ctrl + enter!" name="input" onkeypress="ctrlEnter(event,'+id+')" onchange="saveForm('+id+')" onfocus="saveForm('+id+')" id="input_'+id+'" style="height: 195px" tabindex="'+id+'1">'+(savedInput[id]?savedInput[id]:'')+'</textarea><br />... or upload (max 2 MB):<br /> <input onkeypress="ctrlEnter(event,'+id+')" type="file" name="inputfile" id="inputfile_'+id+'" /></td>'+
	'<td><textarea readonly="readonly" tabindex="'+id+'3" id="output_'+id+'" />'+(savedOutput[id]?savedOutput[id]:'')+'</textarea></td></tr>'+
	'<tr><td><input type="button" class="generate_button" tabindex="'+id+'2" value="Generate output" style="font-weight: bold" title="Tip: You can submit directly from the input-field by hitting ctrl + enter!" onClick="preSubmitData('+id+')" /></td><td>'+
	'<input class="save_button" type="button" tabindex="'+id+'4" value="Save output" '+(savedOutput[id]?'':'disabled="disabled"')+' id="output_button_'+id+'" onclick="window.location=\'getoutput.php?id='+id+'\'" /></td></tr>'+
	'</table>'+
	'</form>';
	
	$(frame).innerHTML = html;
}

function ctrlEnter(event,id) {
  if ((event.ctrlKey) && ((event.keyCode == 0xA)||(event.keyCode == 0xD))) {
    preSubmitData(id);
	}
}

function preSubmitData(id) {
  // is there both an upload and textarea-input?
	if ($('input_'+id).value.length > 0 && $('inputfile_'+id).value.length > 0) {
    // trying to post in both fields, ask the user what to do
    $('lightbox'+id).innerHTML = '<table height="100%" align="center"><tr><td style="padding: 20px;"><img src="/icon_error.png" align="middle" alt="" /></td><td  style="padding: 20px;"><div style="font-size: 18px">Double input</div><div style="font-size: 12px">You have input in the input box as well as having attached a file. You can not post from both at the same time. What would you like to post?</div><br />'+
		'<input type="button" value="Input box" id="choose_input'+id+'" onClick="submitInput('+id+')" /> '+
		'<input type="button" value="Attachment" id="choose_file'+id+'" onClick="submitFile('+id+')" /> '+
		'<input type="button" value="Cancel" onClick="$(\'lightbox'+id+'\').style.display=\'none\'" /></td></tr></table>';
		$('lightbox'+id).style.display = 'block';
		$('choose_input'+id).focus();
	} else {
    submitData(id);
	}
}

function submitInput(id) {
	$('inputfile_'+id).disabled = 'disabled';
	submitData(id);
	$('inputfile_'+id).disabled = '';
}

function submitFile(id) {
	$('input_'+id).disabled = 'disabled';
	submitData(id);
	$('input_'+id).disabled = '';
}

function toggleHidden(id) {
	frame = 'generator_'+id;

	if (currentlyOpen[frame] == 1) {	
		Effect.BlindUp(frame,{restoreAfterFinish: false, duration:0.5, scaleMode: {originalHeight: 300}});
		currentlyOpen[frame] = 2;
	}
	else {
		hiddenForm(id);
	
		// do the effect
		Effect.BlindDown(frame,{restoreAfterFinish: false, duration:0.5, scaleMode: {originalHeight: 300}});
		currentlyOpen[frame] = 1;
	  setTimeout("$('input_"+id+"').focus();",100);
	}
}

function saveForm(id) {
	savedInput[id] = $('input_'+id).value;
	savedOutput[id] = $('output_'+id).value;
}

function submitData(id) {
	$('lightbox'+id).style.display = 'block';
	$('lightbox'+id).innerHTML = '<div style="padding-top: 120px;"><img src="/icon_uploading.png" align="middle" alt="" style="margin-right: 30px;" /> Uploading and parsing...</div>';
	$("form_"+id).submit();
}

// filter keyword-activity
function filter_activity() {
	if (lastInput != $('filter_keyword').value) {
		lastInputChange = true;
	}
	if (lastInputChange == true && lastInput == $('filter_keyword').value) {
		lastInputChange = false;
		filterProblems($('filter_keyword').value);
	}
	lastInput = $('filter_keyword').value;
	
	window.setTimeout("filter_activity()",300);
}

// keep session alive
new Ajax.PeriodicalUpdater('keepalive', 'keepalive.php', {
  method: 'get', frequency: 300, decay: 1
});

updateTable();
