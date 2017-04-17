pipeline {
  agent any
  stages {
    stage('Getting Started') {
      steps {
        parallel(
          "Getting Started": {
            echo 'Hello Pipeline'
            
          },
          "Stage 2 concurrent": {
            echo 'concurrent'
            
          }
        )
      }
    }
    stage('Final step') {
      steps {
        build 'tuan'
      }
    }
  }
}