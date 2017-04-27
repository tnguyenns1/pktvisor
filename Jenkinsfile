pipeline {
  agent any
  stages {
    stage('Getting Started') {
      steps {
        git(url: 'git@github.com:nsone/platform.git', branch: 'develop', credentialsId: '38e5917d-b6a7-4270-a488-260a0d04f833')
      }
    }
    stage('Final step') {
      steps {
        echo 'Final!!'
      }
    }
  }
}