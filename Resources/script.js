var PlayBtn;
var InputPath;
window.onload = function(){
  //alert("Load");
  
  
  try{
    PlayBtn = document.getElementById("Play");
    InputPath = document.getElementById("Path");
    CatalogBtn = document.getElementById("Catalog");
    
    PlayBtn.onclick = function(){
      WindowObj.SearchMusic(InputPath.value);
    };
    
    CatalogBtn.onclick = function(){
      try{
	/*
	alert(WindowObj.JukeboxCatalog.GetSize());
	for(var albumIndex = 0; albumIndex < WindowObj.JukeboxCatalog.GetSize(); albumIndex++){
	  Resultado.innerText += albumIndex +"<br/>";
	}
	*/
      }catch(Exception){
	alert(Exception);
	
      }finally{
	try{
	  Catalog =  JSON.parse(WindowObj.GetCatalog());
	  alert(Catalog.Albums.lenght);
	}catch(Exception){
	  alert(Exception);
	}
      }
    };
    
    
  }catch(Exception){
    alert(Exception);
    Resultado.innerText=Exception.Message;
  }
  
}

//alert(WindowObj);
try{
  
  WindowObj.SetMessage("It Works!");
}catch(Exception){
  
  alert(Exception);
  //Resultado.innerText=Exception.Message;
}
var Catalog;

function ListSongs(catalog){
    for(var i in catalog.Albums){
      console.log(i);
      for(var j in catalog.Albums[i].Tracks){
	console.log(j);
	console.log( catalog.Albums[i].Tracks[j].TrackNumber +".- "+ catalog.Albums[i].Tracks[j].Artist + " - " + catalog.Albums[i].Tracks[j].Title);
	
      }
    }
}
//var Resultado = document.getElementById("Resultado");